/*2452654 郭炫君 电信*/
#include "7-b2.h"
#include "cmd_console_tools.h"
#include <string.h>
#include <conio.h>

using namespace std;
// 判断是否为GB2312汉字
static int is_hanzi(unsigned char c1, unsigned char c2) {
    return (c1 >= 0xA1 && c1 <= 0xFE) && (c2 >= 0xA1 && c2 <= 0xFE);
}

// 计算字符串的显示宽度（汉字宽2，英文宽1）
static int str_display_width(const char* str) {
    int width = 0;
    for (int i = 0; str[i]; ) {
        unsigned char ch = (unsigned char)str[i];
        if (ch >= 0xA1 && is_hanzi(ch, (unsigned char)str[i + 1])) {
            width += 2;
            i += 2;
        }
        else {
            width += 1;
            i++;
        }
    }

    return width;
}

// 安全显示字符串，防止半个汉字溢出
static void safe_showstr(const char* str, int x, int y, int bg, int fg, int max_width) {
    int w = 0, i = 0;

    // 1. 整行先填满背景色（不越界）
    for (int j = 0; j < max_width; ++j) {
        cct_showch(x + j, y, ' ', bg, fg);
    }

    // 2. 输出字符串（自动跳过半个汉字）
    while (str[i] && w < max_width) {
        unsigned char ch = (unsigned char)str[i];
        if (ch >= 0xA1 && is_hanzi(ch, (unsigned char)str[i + 1])) {
            if (w + 2 > max_width) break;
            cct_showstr(x + w, y, str + i, bg, fg, 1, 2);
            w += 2;
            i += 2;
        }
        else {
            cct_showch(x + w, y, str[i], bg, fg);
            w++;
            i++;
        }
    }
}

//绘制标题
static void show_title_str(const char* str, int x, int y, int bg, int fg) {
    int i = 0, w = 0;
    while (str[i]) {
        if (is_hanzi(str[i], str[i + 1])) {
            cct_showstr(x + w, y, str + i, bg, fg, 1, 2);
            w += 2;
            i += 2;
        }
        else {
            cct_showch(x + w, y, str[i], bg, fg); 
            w++;
            i++;
        }
    }
}

// 绘制菜单框及标题
static void draw_menu_frame(const struct PopMenu* original_para, int width, int high) {
    int x = original_para->start_x;
    int y = original_para->start_y;

    // 修正1：总宽度 = 内容宽度 + 左右边框(各1)
    int total_w = width + 2;
    // 总高度 = 内容高度 + 上下边框(各1)
    int total_h = high + 2;

    int console_width, console_lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(console_width, console_lines, buffer_cols, buffer_lines);
    // 填充整个菜单框的背景色
    for (int i = 0; i < total_h; i++) {
        for (int j = 0; j < total_w; j++) {
            cct_showch(x + j, y + i, ' ', original_para->bg_color, original_para->bg_color);
        }
    }

    // 使用字符串方式画边框
    const char* tl = "╔"; // 左上
    const char* tr = "╗"; // 右上
    const char* bl = "╚"; // 左下
    const char* br = "╝"; // 右下
    const char* hz = "═"; // 横线
    const char* vt = "║"; // 竖线

    //线框不超出缓冲区
    if (total_w + x <= buffer_cols) {
        cct_showstr(x, y, tl, original_para->bg_color, original_para->fg_color);
        cct_showstr(x + total_w, y, tr, original_para->bg_color, original_para->fg_color);
        cct_showstr(x, y + total_h - 1, bl, original_para->bg_color, original_para->fg_color);
        cct_showstr(x + total_w, y + total_h - 1, br, original_para->bg_color, original_para->fg_color);


        // 上下横线（从x+1到x+total_w-2）
        for (int i = 1; i < total_w - 1; ++i) {
            cct_showstr(x + i, y, hz, original_para->bg_color, original_para->fg_color);
            cct_showstr(x + i, y + total_h - 1, hz, original_para->bg_color, original_para->fg_color);
        }

        // 左右竖线（从y+1到y+total_h-2）
        for (int i = 1; i < total_h - 1; ++i) {
            cct_showstr(x, y + i, vt, original_para->bg_color, original_para->fg_color);
            cct_showstr(x + total_w, y + i, vt, original_para->bg_color, original_para->fg_color);
        }

        // 居中标题（位于上边框内）
        int title_len = str_display_width(original_para->title);
        int title_x = x + 1 + (total_w - title_len) / 2;
        if (title_x <= x)
            title_x = x + 1;
        for (int i = 0; i < title_len; ++i) {
            cct_showch(title_x + i - 1, y, ' ', original_para->bg_color, original_para->bg_color);
        }
        show_title_str(original_para->title, title_x, y, original_para->bg_color, original_para->fg_color);
    }
    //线框超出缓冲区
    else {
        //打印角框
        cct_showstr(x, y, tl, original_para->bg_color, original_para->fg_color);
        cct_showstr(x + total_w- buffer_cols, y + 1, tr, original_para->bg_color, original_para->fg_color);
        cct_showstr(x, y + total_h - 1, bl, original_para->bg_color, original_para->fg_color);
        cct_showstr(x + total_w-buffer_cols, y + total_h, br, original_para->bg_color, original_para->fg_color);

        //打印上下横线
        for (int i = 1; x+i <= buffer_cols; ++i) {
            cct_showstr(x + i, y, hz, original_para->bg_color, original_para->fg_color);
            cct_showstr(x + i, y + total_h - 1, hz, original_para->bg_color, original_para->fg_color);
        }
        for (int i = 0; i < x + total_w - buffer_cols-1; i++) {
            cct_showstr(i, y+1, hz, original_para->bg_color, original_para->fg_color);
            cct_showstr(i, y + total_h, hz, original_para->bg_color, original_para->fg_color);
        }

        //打印左右竖线
        for (int i = 1; i < total_h - 1; ++i) {
            cct_showstr(x, y + i, vt, original_para->bg_color, original_para->fg_color);
            cct_showstr(x + total_w - buffer_cols, y + i + 1, vt, original_para->bg_color, original_para->fg_color);
        }
        int title_len = str_display_width(original_para->title);
        int title_x = x + 1 + (total_w - title_len) / 2;
        if (title_x <= x)
            title_x = x + 1;
        for (int i = 0; i < title_len; ++i) {
            cct_showch(title_x + i - 1, y, ' ', original_para->bg_color, original_para->bg_color);
        }
        show_title_str(original_para->title, title_x, y, original_para->bg_color, original_para->fg_color);
    }
}



int pop_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
    cct_setcursor(CURSOR_INVISIBLE);  // 隐藏光标

    int width = original_para->width;
    if (width % 2 != 0)
        width++;

    //考虑标题比线框宽，要改变线框长度
    int title_len = str_display_width(original_para->title);
    if (width < title_len)
        width = title_len % 2 == 0 ? title_len : title_len + 1; // 保持偶数宽度
    else if (width % 2 != 0)
        width++; // 保证总是偶数，居中才对称

    int x = original_para->start_x + 2;
    int y = original_para->start_y + 1;

    // 菜单项总数
    int total_items = 0;
    while (menu[total_items][0]) 
        total_items++;

    int visible_lines = original_para->high;
    if (visible_lines > total_items)
        visible_lines = total_items;

    // 初始绘制整个菜单框架和所有可见项
    draw_menu_frame(original_para, width, visible_lines);

    for (int i = 0; i < visible_lines; ++i) {
        int index = i;
        safe_showstr(menu[index], x, y + i, original_para->bg_color, original_para->fg_color, width);
    }

    int cur = 0;
    int scroll_top = 0;
    int prev_cur = -1;  // 记录之前选中的项

    while (true) {
        // 只更新需要变化的部分
        if (prev_cur != cur) {
            // 取消之前选中项的高亮
            if (prev_cur >= scroll_top && prev_cur < scroll_top + visible_lines) {
                int prev_line = prev_cur - scroll_top;
                safe_showstr(menu[prev_cur], x, y + prev_line,original_para->bg_color, original_para->fg_color, width);
            }

            // 高亮当前选中项
            if (cur >= scroll_top && cur < scroll_top + visible_lines) {
                int cur_line = cur - scroll_top;
                safe_showstr(menu[cur], x, y + cur_line,original_para->fg_color, original_para->bg_color, width);
            }
            prev_cur = cur;
        }

        int key = _getch();
        if (key == 224 || key == 0) {
            key = _getch();
            if (key == KB_ARROW_UP) {
                if (cur > 0) {
                    cur--;
                }
            }
            else if (key == KB_ARROW_DOWN) {
                if (cur < total_items - 1) {
                    cur++;
                }
            }
            else {
                continue;  // 忽略其他方向键
            }

            // 滚动控制
            if (cur < scroll_top) {
                // 需要向上滚动
                scroll_top = cur;
                for (int i = 0; i < visible_lines; ++i) {
                    int index = scroll_top + i;
                    if (index >= total_items) {
                        safe_showstr("", x, y + i, original_para->bg_color, original_para->fg_color, width);
                        continue;
                    }
                    int bg = (index == cur) ? original_para->fg_color : original_para->bg_color;
                    int fg = (index == cur) ? original_para->bg_color : original_para->fg_color;
                    safe_showstr(menu[index], x, y + i, bg, fg, width);
                }
                prev_cur = cur;  // 避免重复处理
            }
            else if (cur >= scroll_top + visible_lines) {
                // 需要向下滚动
                scroll_top = cur - visible_lines + 1;
                for (int i = 0; i < visible_lines; ++i) {
                    int index = scroll_top + i;
                    if (index >= total_items) {
                        safe_showstr("", x, y + i, original_para->bg_color, original_para->fg_color, width);
                        continue;
                    }
                    int bg = (index == cur) ? original_para->fg_color : original_para->bg_color;
                    int fg = (index == cur) ? original_para->bg_color : original_para->fg_color;
                    safe_showstr(menu[index], x, y + i, bg, fg, width);
                }
                prev_cur = cur;  // 避免重复处理
            }
        }
        else if (key == '\r') {
            break;
        }
    }
    // 空菜单处理
    if (total_items == 0)
        return 0;

    cct_setcursor(CURSOR_VISIBLE_NORMAL);  // 恢复光标
    return cur + 1;  // 从1开始编号
}
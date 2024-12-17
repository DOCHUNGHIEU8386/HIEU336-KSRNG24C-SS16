#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void nhapChuoi(char **str) {
    char temp[1000];
    printf("Nhap chuoi: ");
    scanf(" %[^"]s", temp);
    *str = strdup(temp); 
}

void inDaoNguoc(char *str) {
    if (str != NULL) {
        int len = strlen(str);
        printf("Chuoi dao nguoc: ");
        for (int i = len - 1; i >= 0; i--) {
            putchar(str[i]);
        }
        printf("\n");
    } else {
        printf("Chuoi chua duoc nhap.\n");
    }
}

int demSoTu(char *str) {
    int dem = 0;
    int inWord = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i]) && !inWord) {
            inWord = 1;
            dem++;
        } else if (isspace(str[i])) {
            inWord = 0;
        }
    }
    return dem;
}

void soSanhChuoi(char *str1) {
    if (str1 == NULL) {
        printf("Chuoi chua duoc nhap.\n");
        return;
    }

    char temp[1000];
    printf("Nhap chuoi khac: ");
    scanf(" %[^"]s", temp);

    int len1 = strlen(str1);
    int len2 = strlen(temp);

    if (len1 > len2) {
        printf("Chuoi ban nhap ngan hon chuoi ban dau.\n");
    } else if (len1 < len2) {
        printf("Chuoi ban nhap dai hon chuoi ban dau.\n");
    } else {
        printf("Hai chuoi co do dai bang nhau.\n");
    }
}

void inHoaChuoi(char *str) {
    if (str != NULL) {
        printf("Chuoi in hoa: ");
        for (int i = 0; str[i] != '\0'; i++) {
            putchar(toupper(str[i]));
        }
        printf("\n");
    } else {
        printf("Chuoi chua duoc nhap.\n");
    }
}

void themChuoi(char **str) {
    if (*str == NULL) {
        printf("Chuoi ban dau chua duoc nhap.\n");
        return;
    }

    char temp[1000];
    printf("Nhap chuoi khac: ");
    scanf(" %[^"]s", temp);

    *str = realloc(*str, strlen(*str) + strlen(temp) + 1);
    if (*str == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    strcat(*str, temp);
    printf("Chuoi sau khi them: %s\n", *str);
}

int main() {
    char *str = NULL;
    int luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. So sanh voi chuoi khac\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Them chuoi khac vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
        case 1:
            nhapChuoi(&str);
            break;
        case 2:
            inDaoNguoc(str);
            break;
        case 3:
            if (str != NULL) {
                printf("So luong tu trong chuoi: %d\n", demSoTu(str));
            } else {
                printf("Chuoi chua duoc nhap.\n");
            }
            break;
        case 4:
            soSanhChuoi(str);
            break;
        case 5:
            inHoaChuoi(str);
            break;
        case 6:
            themChuoi(&str);
            break;
        case 7:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while (luaChon != 7);

    free(str);

    return 0;
}


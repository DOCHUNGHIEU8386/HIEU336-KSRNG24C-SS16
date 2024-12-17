#include <stdio.h>
#include <string.h>
#include <ctype.h>

void nhapChuoi(char **str) {
    char temp[1000];
    printf("Nhap chuoi: ");
    scanf(" %[^"]s", temp);
    *str = strdup(temp); 
}

void inChuoi(char *str) {
    if (str != NULL) {
        printf("Chuoi: %s\n", str);
    } else {
        printf("Chuoi chua duoc nhap.\n");
    }
}

int demChuCai(char *str) {
    int dem = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) dem++;
    }
    return dem;
}

int demChuSo(char *str) {
    int dem = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) dem++;
    }
    return dem;
}

int demKyTuDacBiet(char *str) {
    int dem = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && !isspace(str[i])) dem++;
    }
    return dem;
}

int main() {
    char *str = NULL;
    int luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai\n");
        printf("4. Dem so luong chu so\n");
        printf("5. Dem so luong ky tu dac biet\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
        case 1:
            nhapChuoi(&str);
            break;
        case 2:
            inChuoi(str);
            break;
        case 3:
            if (str != NULL) {
                printf("So luong chu cai: %d\n", demChuCai(str));
            } else {
                printf("Chuoi chua duoc nhap.\n");
            }
            break;
        case 4:
            if (str != NULL) {
                printf("So luong chu so: %d\n", demChuSo(str));
            } else {
                printf("Chuoi chua duoc nhap.\n");
            }
            break;
        case 5:
            if (str != NULL) {
                printf("So luong ky tu dac biet: %d\n", demKyTuDacBiet(str));
            } else {
                printf("Chuoi chua duoc nhap.\n");
            }
            break;
        case 6:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while (luaChon != 6);

    free(str);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void nhapMang(int **arr, int *n) {
    printf("Nhap so phan tu: ");
    scanf("%d", n);
    *arr = (int *)malloc((*n) * sizeof(int));
    if (*arr == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    printf("Nhap cac phan tu:");
    for (int i = 0; i < *n; i++) {
        scanf("%d", &(*arr)[i]);
    }
}

void inSoChan(int *arr, int n) {
    printf("Cac phan tu la so chan: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) printf("%d ", arr[i]);
    }
    printf("\n");
}

bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void inSoNguyenTo(int *arr, int n) {
    printf("Cac phan tu la so nguyen to: ");
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(arr[i])) printf("%d ", arr[i]);
    }
    printf("\n");
}

void daoNguocMang(int *arr, int n) {
    printf("Mang dao nguoc: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sapXepMang(int *arr, int n, bool tangDan) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((tangDan && arr[i] > arr[j]) || (!tangDan && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Mang sau khi sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void timKiemPhanTu(int *arr, int n) {
    int x, found = 0;
    printf("Nhap phan tu can tim: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("Phan tu %d co trong mang tai vi tri %d\n", x, i);
            found = 1;
        }
    }
    if (!found) printf("Phan tu %d khong co trong mang.\n", x);
}

int main() {
    int *arr = NULL;
    int n = 0, luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va cac phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("   5.1. Tang dan\n");
        printf("   5.2. Giam dan\n");
        printf("6. Tim kiem phan tu trong mang\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
        case 1:
            nhapMang(&arr, &n);
            break;
        case 2:
            inSoChan(arr, n);
            break;
        case 3:
            inSoNguyenTo(arr, n);
            break;
        case 4:
            daoNguocMang(arr, n);
            break;
        case 5: {
            int subChoice;
            printf("1. Tang dan\n2. Giam dan\nLua chon: ");
            scanf("%d", &subChoice);
            sapXepMang(arr, n, subChoice == 1);
            break;
        }
        case 6:
            timKiemPhanTu(arr, n);
            break;
        case 7:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
        }
    } while (luaChon != 7);

    free(arr);
    return 0;
}


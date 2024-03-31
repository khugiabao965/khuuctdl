#include <stdio.h>

// H�m nh?p m?ng
void nhapMang(int arr[], int n) {
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

// H�m xu?t m?ng
void xuatMang(int arr[], int n) {
    printf("Cac phan tu cua mang la:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// H�m t?m ki?m tuy?n t�nh
int timKiemTuyenTinh(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return 1; // T?m th?y
        }
    }
    return 0; // Kh�ng t?m th?y
}

// H�m t?m ki?m nh? ph�n (y�u c?u m?ng �? ��?c s?p x?p)
int timKiemNhiPhan(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            return mid; // T?m th?y
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Kh�ng t?m th?y
}

// H�m ki?m tra s? nguy�n t?
int laSoNguyenTo(int num) {
    if (num < 2)
        return 0; // Kh�ng ph?i s? nguy�n t?
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0; // Kh�ng ph?i s? nguy�n t?
    }
    return 1; // L� s? nguy�n t?
}

int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    nhapMang(arr, n);

    // Hi?n th? menu
    printf("\nMenu:\n");
    printf("1. Tim kiem tuyen tinh\n");
    printf("2. Tim kiem nhi phan (yeu cau mang da sap xep)\n");
    printf("3. Tim so nguyen to\n");
    printf("Chon chuc nang: ");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // T?m ki?m tuy?n t�nh
            {
                int x;
                printf("Nhap so can tim: ");
                scanf("%d", &x);
                if (timKiemTuyenTinh(arr, n, x)) {
                    printf("%d co trong mang.\n", x);
                } else {
                    printf("%d khong co trong mang.\n", x);
                }
            }
            break;

        case 2:
            // T?m ki?m nh? ph�n
            {
                int x;
                printf("Nhap so can tim: ");
                scanf("%d", &x);
                int index = timKiemNhiPhan(arr, 0, n - 1, x);
                if (index != -1) {
                    printf("%d co trong mang tai vi tri %d.\n", x, index);
                } else {
                    printf("%d khong co trong mang.\n", x);
                }
            }
            break;

        case 3:
            // T?m s? nguy�n t?
            {
                int count = 0;
                printf("Cac so nguyen to trong mang la:\n");
                for (int i = 0; i < n; i++) {
                    if (laSoNguyenTo(arr[i])) {
                        printf("%d tai vi tri %d\n", arr[i], i);
                        count++;
                    }
                }
                printf("Tong cong co %d so nguyen to trong mang.\n", count);
            }
            break;

        default:
            printf("Lua chon khong hop le.\n");
            break;
    }

    return 0;
}

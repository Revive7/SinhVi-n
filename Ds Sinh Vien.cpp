#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
 
using namespace std;
struct Sinhvien
{
	char Hoten[50],Mssv[20],Monhoc[20];
	float Diem;
	int low;
	int high;
};
typedef Sinhvien sinhvien;
void nhap(Sinhvien &sv);
void nhapsv(Sinhvien a[], int n);
void xuat(Sinhvien &sv);
void xuatsv(Sinhvien a[], int n);
void Bubblesort(Sinhvien a[], int n);
void InterchangeSort(Sinhvien a[], int n);
int main(){
    int key;
    char fileName[] = "DSSVV.txt";
    int n;
    bool Nhap = false;
    do{
        printf("\nNhap so luong SV: "); scanf("%d", &n);
    }while(n <= 0);
    Sinhvien a[n];
    while(true){
        system("cls");
        printf("******************************************\n");
        printf("**    CHUONG TRINH QUAN LY SINH VIEN    **\n");
        printf("**      1. Nhap du lieu                 **\n");
        printf("**      2. In danh sach sinh vien       **\n");
        printf("**      3. Sap xep sinh vien theo diem   **\n");
        printf("**      0. Thoat                        **\n");
        printf("******************************************\n");
        printf("**       Nhap lua chon cua ban          **\n");
        scanf("%d",&key);
        switch(key){
            case 1:
                printf("\nBan da chon nhap DS sinh vien!");
                nhapsv(a, n);
                printf("\nBan da nhap thanh cong!");
                Nhap = true;
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 2:
                if(Nhap){
                    printf("\nBan da chon xuat DS sinh vien!");
                    xuatsv(a, n);
                }else{
                    printf("\nVui long nhap DS sinh vien");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 3:
                if(Nhap){
                    printf("\nBan da chon sap xep SV theo diem!");
                    Bubblesort(a, n);
                    InterchangeSort(a, n);
                    xuatsv(a, n);
                }else{
                    printf("\nVui long nhap DS sinh vien");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 0:
                printf("\nBan da chon thoat chuong trinh!");
                getch();
                return 0;
            default:
                printf("\nKhong co chuc nang nay!");
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
        }
    }
    Sinhvien sv;
	nhap(sv);
	xuat(sv);
	getch();
}
void nhap(Sinhvien &sv){
    printf("\nNhap Ho Va Ten: "); fflush(stdin); gets(sv.Hoten);
    printf("\nNhap MSSV: "); fflush(stdin); gets(sv.Mssv);
    printf("\nNhap Ten Mon Hoc: "); fflush(stdin); gets(sv.Monhoc);
    fflush(stdin);
     do{
		printf("\nNhap Vao Diem: ");
		scanf("%f", &sv.Diem);

		if(sv.Diem < 0 || sv.Diem > 10)
		{
			printf("\nDiem tu 0 den 10!\nVui long kiem tra lai! ");
		}
	}while(sv.Diem < 0 || sv.Diem > 10);
}
void nhapsv(Sinhvien a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0; i< n; ++i){
        printf("\nNhap SV thu %d:", i+1);
        nhap(a[i]);
    }
    printf("\n____________________________________\n");
}
void xuat(Sinhvien &sv){
    printf("\nHo Va Ten Sinh Vien: %s", sv.Hoten);
    printf("\nMa So Sinh Vien SV: %s", sv.Mssv);
	printf("\nTen Mon Hoc: %s", sv.Monhoc);
	printf("\nDiem Mon Hoc: %f", sv.Diem);	
}
void outputsv(Sinhvien a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0;i < n;++i){
        printf("\nThong tin SV thu %d:", i+1);
        xuat(a[i]);
    }
    printf("\n____________________________________\n");
}
void Bubblesort(struct Sinhvien a[], int n)
{
int i, j;
for (i = 0; i < n; i++)
for (j = n - 1; j > i; j--)
if (a[j].Diem < a[j - 1].Diem )
{
sinhvien temp = a[j];
a[j] = a[j - 1];
a[j - 1] = temp;
}
}
void InterchangeSort(struct Sinhvien a[], int n)
{
 sinhvien temp;
   for (int i = 0; i < n ; i++)
      for (int j = i+1; j < n; j++)
         if (a[i].Diem < a[j].Diem)
         {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
         }
}

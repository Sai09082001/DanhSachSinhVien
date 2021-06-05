#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// bai 1

struct SinhVien
{
    char maSV[25];
    char lop[10];
    int tuoi;
    char hoTen[25];
};


struct Node
{
	SinhVien data;
	Node *pNext;
};

SinhVien themSVNode ()
{
    SinhVien a;

    printf("Nhap ho ten: ");
    fflush(stdin);
    gets(a.hoTen);

    printf("Lop: ");
    fflush(stdin);
    gets(a.lop);

    printf("Tuoi: ");
    scanf("%d",&a.tuoi);

    printf("Ma SV: ");
    fflush(stdin);
    gets(a.maSV);

    return a;
}

struct List
{
	Node *pHead;
	Node *pTail;
};

void TaoList(List &l)
{

	l.pHead = NULL;
	l.pTail = NULL;
}


Node* TaoNode()
{

	Node *p = (Node*)malloc(sizeof (Node));
	p->data = themSVNode();
	p->pNext = NULL;
	return p;
}

void ThemVaoDau(List &l, Node* p)
{

	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}


void ThemVaoCuoi(List &l)
{
    //Tao node
    Node* p = TaoNode();

    if (l.pHead ==NULL)
        l.pHead  = p;

    else
    {
        Node* k;
        for (k=l.pHead; k->pNext!=NULL; k=k->pNext);

        k->pNext = p;
    }
}


void HienThiSinhVien(SinhVien sv){
   printf("%s",sv.hoTen);
   printf("%s",sv.maSV);
   printf("%s",sv.lop);
   printf("%d ",sv.tuoi);
}

void HienThiDanhSachSinhVien(List l){

    if (l.pHead==NULL)
    {
        printf("Danh sach rong\n");
        return;
    }

    Node* i;
    int stt;
    printf("\t\tDANH SACH\n");


    for (stt=1,i=l.pHead ; i!=NULL; i=i->pNext)
    {
        printf("%d",stt++);
        HienThiSinhVien(i->data);
    }
    printf("\n");
}

Node* timSVTrongDanhSach (char hoTen[])
{
	List l;
    Node* i;
    for (i=l.pHead; i!=NULL;i=i->pNext)
        if (strcmp(hoTen,i->data.hoTen)==0)
            break;
    return i;
}

Node* timSinhVienTrongDanhSach (char maSV[])
{
	List l;
    Node* i;
    for (i=l.pHead; i!=NULL;i=i->pNext)
        if (strcmp(maSV,i->data.maSV)==0)
            break;
    return i;
}

void sapXepDanhSachTheoMaSVTangDan(List l)
{
	SinhVien x;

    Node* i;
    Node* j;
    if (l.pHead==NULL)
        return;

    for (i=l.pHead; i->pNext!=NULL; i=i->pNext)
    {
        for (j=i->pNext;j!=NULL; j=j->pNext)
        {
            if (strcmp(j->data.maSV,i->data.maSV)<0)
            {
                SinhVien x = i->data;
                i->data = j->data;
                j->data = x;
            }
        }
    }
}

void menu()
{
    printf("\t\tMENU\n");
    printf("\t1. Nhap danh sach sinh vien\n");
    printf("\t2. In danh sach sinh vien\n");
    printf("\t3. Tim kiem sinh vien theo ten\n");
    printf("\t4. Sap xep sinh vien theo ma sinh vien\n");
    printf("\t5. Tim kiem sinh vien theo ma sinh vien\n");
    printf("\t6. Exit\n");
    printf("\t-------------------------\n");
    printf("\t\tVui long chon: ");
}

int main()
{
	List l;
	int i=0;
	int chon;
	int n = 0;
    char hoTen[25];
    char maSV[25];
    Node* m= NULL;
    do
    {
        system("cls");
        //In menu
        menu();

        //Chon option
        scanf("%d",&chon);

        //Thuc hien option
        switch(chon)
        {
            case 1:
                //Neu da co danh sach sinh vien
                if (n>0)
                {
                    //Xoa danh sach cu
                    l.pHead = NULL;
                }

                //Chua co dssv
                //Nhap so luong sinh vien
                printf("Nhap so luong sinh vien: ");
                scanf("%d",&n);

                //Nhap tung sinh vien mot
                for (i=0; i<n; i++)
                {
                    printf("Nhap sinh vien thu %d\n",i+1);
                    ThemVaoCuoi(l);
                }


                printf("\tBan da nhap xong danh sach sinh vien\n");

                break;
            case 2:
                HienThiDanhSachSinhVien(l);
                break;
            case 3:
                if (l.pHead==NULL)
                {
                    printf("\tVui long nhap danh sach\n");
                    break;
                }
                printf("Nhap ten can tim kiem: ");
                fflush(stdin);
                gets(hoTen);
                m = timSVTrongDanhSach(hoTen);
                if (m==NULL)
                    printf("Khong ton tai sinh vien %s\n",hoTen);
                else
                {
                    printf("Thong tin sinh vien %s\n",hoTen);
                    HienThiSinhVien(m->data);
                }
                break;
            case 4:
                if (l.pHead==NULL)
                {
                    printf("\tVui long nhap danh sach\n");
                    break;
                }
                sapXepDanhSachTheoMaSVTangDan(l);
                break;
            case 5:
                if (l.pHead==NULL)
                {
                    printf("\tVui long nhap danh sach\n");
                    break;
                }
                printf("Nhap ma sinh vien can tim kiem: ");
                fflush(stdin);
                gets(maSV);
                m = timSinhVienTrongDanhSach(maSV);
                if (m==NULL)
                    printf("Khong ton tai sinh vien %s\n",maSV);
                else
                {
                    printf("Thong tin sinh vien %s\n",maSV);
                    HienThiSinhVien(m->data);
                }
                break;
            case 6:
                 break;
            default:
                printf("Ban chon sai. Moi ban chon lai MENU!\n");
                break;
        }
    }
	while(chon!=6);

return 0;
}

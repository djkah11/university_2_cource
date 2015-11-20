#include <stdio.h>
#include <string.h>
struct SalesOrderDetail {
    int SalesOrderID;
    int SalesOrderDetailID;
    int OrderQty;
    int ProductID;
    float UnitPrice;
    float UnitPriceDiscount;
    char ModifiedDate[20];
} ;
struct SalesOrderDetail S[1000];
// Объявление узла двоичного дерева.
struct BTree
{
    double szText;
    struct BTree *Left;
    struct BTree *Right;
};



struct BTree* create_node( char name)
{
    struct BTree *node;

    node = malloc(sizeof(struct BTree));

    if (node)
    {
        node->szText= name;

        node->Left = NULL;
        node->Right = NULL;
    }

    return node;
}

struct BTree* insert(struct BTree*tree, struct BTree* node)
{
    int cmp;

    if (tree == NULL)
        return node;

   if ( node->szText> tree->szText) cmp=1 ; else cmp=-1;
    if (cmp == 0)
    {

    }
    else if (cmp < 0)
    {
        tree->Left = insert(tree->Left, node);
    }
    else
    {
        tree->Right = insert(tree->Right, node);
    }

    return tree;
}


void PrintTree( struct BTree* btRoot )
{
    // Пройти левое поддерево (в обратном порядке).
    if( btRoot->Left )
        PrintTree( btRoot->Left );

    // Попасть в корень.
   printf("%lf\n",btRoot->szText);

    // Пройти правое поддерево (в обратном порядке).
    if( btRoot->Right )
        PrintTree( btRoot->Right );
}

int menu()
{
    int i=0;
    printf("Choose number of paragraph for working:\n");
    printf("1)SalesOrderID\n");
    printf("2)SalesOrderDetailID\n");
    printf("3)OrderQty\n");
    printf("4)ProductID\n");
    printf("5)UnitPrice\n");
    printf("6)UnitPriceDiscount\n");
    printf(">>");
    scanf("%d",&i);

    return i;
}

int menu2()
{
    int i=0;
    printf("Choose function:\n");
    printf("1)Print:\n");
    printf("2)Min:\n");
    printf("3)Max:\n");
    printf("4)Successor:\n");
    printf("5)PREDECESSOR\n");
    printf("6)Delete\n");
    printf(">>");
    scanf("%d",&i);

    return i;

}

struct BTree * search (struct BTree * tree, double key)
{
   struct SalesOrderDetail  *buf;

    if (tree)
        do
        {
            buf=tree;
            if (tree->szText==key)
                return NULL;
            if (key<tree->szText)
                tree=tree->Left;
            else
                tree=tree->Right;
        } while (tree);

        return buf;
}
void print_Tree(struct BTree * p,double level)
{
    if(p)
    {
        print_Tree(p->Left,level + 1);
        for(int i = 0;i< level;i++) printf("   ");
        printf("%lf\n",p->szText) ;
        print_Tree(p->Right,level + 1);
    }
    return;
}
int main()
{
        int len=0;
        FILE *fp=fopen("SalesOrderDetails.xml","r");
        char s[100];
        char * pch;
        fgets(s,99,fp);
        strcpy(s,"");
        int i=0;
        while(1)
        {
            len++;
         fgets(s,99,fp);
         if (!strcmp(s,"</ROOT>")) break;
         strcpy(s,"");
          fgets(s,99,fp);//первый
           pch = strtok (s,"<SalesOrderID>");
           pch = strtok (NULL,"<\SalesOrderID>");
           S[i].SalesOrderID=atoi(pch);
           strcpy(s,"");
           fgets(s,99,fp); //второй
           pch = strtok (s,"<SalesOrderDetailID>");
           pch = strtok (NULL,"<\\SalesOrderDetailID>");
           S[i].SalesOrderDetailID=atoi(pch);
           strcpy(s,"");
           fgets(s,99,fp); //третий
           pch = strtok (s,"<OrderQty>");
           pch = strtok (NULL,"<\\OrderQty>");
           S[i].OrderQty=atoi(pch);

           strcpy(s,"");
           fgets(s,99,fp); //четвертый
           pch = strtok (s,"<ProductID>");
           pch = strtok (NULL,"<\\ProductID>");
           S[i].ProductID=atoi(pch);
           strcpy(s,"");
           fgets(s,99,fp); //пятый
           pch = strtok (s,"<UnitPrice>");
           pch = strtok (NULL,"<\\UnitPrice>");
           S[i].UnitPrice=atof(pch);

           //printf("%lf\n",atof(pch));
           strcpy(s,"");
           fgets(s,99,fp); //шестой
           pch = strtok (s,"<UnitPriceDiscount>");
           pch = strtok (NULL,"<\\UnitPriceDiscount>");
           S[i].UnitPriceDiscount=atof(pch);
           // printf("%sH %lf \n",pch,atof(pch));
           strcpy(s,"");
           fgets(s,99,fp); //седьмой
           pch = strtok (s,"<ModifiedDate>");
           pch = strtok (NULL,"<\\ModifiedDate>");
            strcpy(S[i].ModifiedDate,pch);
           strcpy(s,"");
           fgets(s,99,fp);
           strcpy(s,"");
           i++;
    }
        //считатали файл в массив и перегоняем в числовой массив, из которого построим дерево
           int par=menu();
           double yy[len];
           switch (par)
           {
               case 1:
              {
                  for(int i=0;i<len;i++)
                      yy[i]=1.0*S[i].SalesOrderID;
                  break;
              };

              case 2:
             {
              for(int i=0;i<len;i++)
                  yy[i]=1.0*S[i].SalesOrderDetailID;
              break;
             };
               case 3:

              {
               for(int i=0;i<len;i++)
                   yy[i]=1.0*S[i].OrderQty;
               break;
              };

               case 4:
              {
               for(int i=0;i<len;i++)
                   yy[i]=1.0*S[i].ProductID;
               break;
              };

               case 5:
              {
               for(int i=0;i<len;i++)
                   yy[i]=1.0*S[i].UnitPrice;
               break;
              };
               case 6:
              {
               for(int i=0;i<len;i++)
                   yy[i]=1.0*S[i].UnitPriceDiscount;
               break;
              };


           }
struct BTree root=NULL;

    do
    {
        int u=menu2();
        switch (u)
        {
            case 1:
            {
                print_Tree(struct BTree * p,double level)
            }

        }

    }while (1);

    return 0;
}

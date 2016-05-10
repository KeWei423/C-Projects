#include "poly.h"

/*constructor*/
poly::poly(): size(1)
{
    coef = NULL;
}

poly::poly(int *coefficient, int degree): size(degree +1)
{
    coef = Allocate(size);
    int *coefWalker = coef;
    for(int i = 0; i<size; i++)
    {
        *coefWalker = *coefficient;
        coefWalker++;
        coefficient++;
    }

}


//===========
// the big 3
//===========
poly::poly(const poly& OtherPoly)
{
    size = OtherPoly.size;
    coef = Allocate(size);
    Copy(OtherPoly.coef, coef, size);
}

/*destructor*/
poly:: ~poly()
{
    delete [] coef;
    coef = NULL;
}

/*assignment operator*/
poly& poly:: operator = (const poly& RHS)
{
    if(&RHS !=this)
    {
        delete [] coef;
        size = RHS.size;
        coef = Allocate(size);
        Copy(RHS.coef, coef, size);
    }
    return *this;
}


/*Member functions*/
void poly::Copy(int *source, int *dest, int length)
{
    int* sourceWalker = source;
    for(int i=0; i<length; i++)
    {
        *dest = *sourceWalker;
        sourceWalker++;
        dest++;
    }
}

int* poly:: Allocate(int size)
{
    int *temp_ptr = new int [size];
    return temp_ptr;
}

bool rhsIsBigger(const poly& LHS, const poly& RHS)
{
    if(LHS.size >= RHS.size)
    {
        return true;
    }
    else
    {
        return false;
    }

}


void poly::Init(int *ptr, int size)
{
    int* walker = ptr;
    for(int i = 0; i<size; i++, walker++)
    {
        *walker = 0;
    }
}


/*operator functions*/
istream& operator >> (istream& input, poly& inputThis)
{
    int coeff;
    int highest_pow;

    cout<<"enter highest power. ";
    input>>highest_pow;
    int *coeffArray = new int [highest_pow+1];
    int *walker = coeffArray;
    cout<<"Enter coefficient from hightest power"<<endl;
    for(int i =0 ; i < highest_pow+1 ; i++)
    {
        input>>coeff;
        *walker=coeff;
        walker++;
    }
    inputThis = poly (coeffArray,highest_pow);
    return input;
}


ostream& operator << (ostream& output, const poly& printMe)
{
    int size = printMe.size;
    int* coefWalker = printMe.coef+size-1;
    for(int i=size-1; i >0; i--)
    {
        output<<*coefWalker<<"x^"<<i<<" + ";
        coefWalker--;
    }
    output<<*coefWalker;
    return output;
}


poly operator + (const poly& LHS, int rhs)
{
    int* LHSWalker = LHS.coef;
    *LHSWalker = *LHSWalker+rhs;
    return LHS;
}


poly operator + (int lhs, const poly& RHS)
{
    int* RHSWalker = RHS.coef;
    *RHSWalker = *RHSWalker+lhs;
    return RHS;
}




poly operator + (const poly& LHS, const poly& RHS)
{
    bool RHSisBigger = rhsIsBigger(LHS, RHS);
    poly sum;
    int size;
    int* NewStorage;
    int* LHSWalker = LHS.coef;
    int* RHSWalker = RHS.coef;
    if(RHSisBigger)
    {
        size = RHS.size;
        NewStorage = sum.Allocate(RHS.size);
    }
    else
    {
        size = LHS.size;
        NewStorage = sum.Allocate(LHS.size);
    }

    int* NewStorageWalker = NewStorage;
    for(int i= 0 ; i <size; i++)
    {
//        cout<<"i: "<<i<<"LHS: "<<*LHSWalker<<" RHS: "<<*RHSWalker<<endl;
        *NewStorageWalker = *LHSWalker + *RHSWalker;
        LHSWalker++;
        RHSWalker++;
        NewStorageWalker++;
    }
    sum = poly(NewStorage, size-1);
    return sum;
}


poly operator - (const poly& LHS, int rhs)
{
    int* LHSWalker = LHS.coef;
    *LHSWalker = *LHSWalker-rhs;
    return LHS;
}


poly operator - (int lhs, const poly& RHS)
{
    int* RHSWalker = RHS.coef;
    int *temp = RHSWalker;
    for(int i=0; i<RHS.size; i++, temp++)
    {
        *temp = -(*temp);
    }
    delete temp;
    *RHSWalker = *RHSWalker - lhs;
    return RHS;
}


poly operator - (const poly& LHS, const poly& RHS)
{
    bool RHSisBigger = rhsIsBigger(LHS, RHS);
    poly dif;
    int size;
    int* NewStorage;
    int* LHSWalker = LHS.coef;
    int* RHSWalker = LHS.coef;
    if(RHSisBigger)
    {
        size = RHS.size;
        NewStorage = dif.Allocate(RHS.size);
    }
    else
    {
        size = LHS.size;
        NewStorage = dif.Allocate(LHS.size);
    }

    int* NewStorageWalker = NewStorage;
    for(int i= 0 ; i <size; i++)
    {
        cout<<"i: "<<i<<"LHS: "<<*LHSWalker<<" RHS: "<<*RHSWalker<<endl;
        *NewStorageWalker = *LHSWalker - *RHSWalker;
        LHSWalker++;
        RHSWalker++;
        NewStorageWalker++;
    }
    dif = poly(NewStorage, size-1);
    return dif;
}


poly operator * (const poly& LHS, int rhs)
{
    poly prod;
    int size = LHS.size;
    int* LHSWalker = LHS.coef;
    int* product = prod.Allocate(size);
    int* productWalker = product;
    for(int i =0; i<size; i++)
    {
        *productWalker = rhs * (*LHSWalker);
        LHSWalker++;
        productWalker++;
    }
    prod = poly(product, size-1);
    return prod;
}


poly operator * (int lhs, const poly& RHS)
{
    poly pro = RHS * lhs;
    return pro;
}


poly operator * (const poly& LHS, const poly& RHS)
{
    poly pro;
    //1 create size for product
    int size = LHS.size + RHS.size -1;
    //2 create pointer for product and init all element to 0
    int* product = pro.Allocate(size);
    pro.Init(product, size);
    //3 LHS pointer
    int* LHSWalker = LHS.coef;

    for(int i = 0; i < LHS.size; i++, LHSWalker++)
    {
        //4 create walker for product
        int* productWalker = product+i;
        //5 call operator * (int rhs, const poly& RHS)
        poly temp = (*LHSWalker) * RHS;
        int* tempWalker = temp.coef;
        //fill in the proudct array
        for(int i= 0; i < RHS.size; i++)
        {
            *productWalker = *productWalker +*tempWalker;
            productWalker ++;
            tempWalker++;
        }
        productWalker = NULL;
        tempWalker = NULL;
        delete productWalker;
        delete tempWalker;

    }

    pro = poly(product, size-1);
    return pro;
}

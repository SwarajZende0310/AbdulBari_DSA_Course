#include <iostream>

using namespace std;

struct Array
{
    int*A;
    int sz;
    int length;//number of elements in an array
};

void Display(struct Array a)
{
    cout<<"Elements of an Array are: ";
    for(int i=0;i<a.length;i++)
    {
        cout<<a.A[i]<<" ";
    }
    cout<<endl;
}

void Append(struct Array &a,int x)
{
    if(a.length<a.sz)
    {
        a.A[a.length]=x;
        a.length++;
    }
}

void Insert(struct Array &a,int index,int n)
{
    if(index>=0 && index<=a.length)
    {
        for(int i=a.length;i>index;i--)
        {
            a.A[i]=a.A[i-1];
        }
        a.A[index]=n;
        a.length++;
    }
}

int Delete(struct Array &a,int index)
{
    int x=0;
    if(index>=0 && index<a.length)
    {
        x=a.A[index];
        for(int i=index;i<a.length;i++)
        {
            a.A[i]=a.A[i+1];
        }
        a.length--;
        return x;
    }
    return -1;
}

int LinearSearch(struct Array a,int key)
{
    for(int i=0;i<a.length;i++)
    {
        if(key==a.A[i])
        {
            return i;
        }
    }
    return -1;
}

int TranspositionLinearSearch(struct Array &a,int key)
{
    for(int i=0;i<a.length;i++)
    {
        if(key==a.A[i])
        {
            swap(a.A[i],a.A[i-1]);
            return (i-1);
        }
    }
    return -1;
}

int BackToFrontLinearSearch(struct Array &a,int key)
{
    for(int i=0;i<a.length;i++)
    {
        if(key==a.A[i])
        {
            swap(a.A[i],a.A[0]);
            return 0;
        }
    }
    return -1;
}

int BinarySearch(struct Array a,int key)
{
    int l=0,h=a.length-1,mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==a.A[mid])
            return mid;
        else if(key<a.A[mid])
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
}

int RBinarySearch(int l,int h,struct Array a,int key)
{
    int mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==a.A[mid])
            return mid;
        else if(key<a.A[mid])
            return RBinarySearch(l,mid-1,a,key);
        else
            return RBinarySearch(mid+1,h,a,key);
    }
    return -1;
}

int Get(struct Array a,int index)
{
    if(index>=0 && index<a.length)
    {
        return a.A[index];
    }
    return -1;
}

void Set(struct Array &a,int index,int x)
{
    if(index>=0 && index<a.length)
    {
        a.A[index]=x;
    }
}

int Max(struct Array a)
{
    int Max=a.A[0];
    for(int i=0;i<a.length;i++)
    {
        if(a.A[i]>Max)
        {
            Max=a.A[i];
        }
    }
    return Max;
}

int Min(struct Array a)
{
    int Min=a.A[0];
    for(int i=0;i<a.length;i++)
    {
        if(a.A[i]<Min)
        {
            Min=a.A[i];
        }
    }
    return Min;
}

int sum(struct Array a)
{
    int s=0;
    for(int i=0;i<a.length;i++)
    {
        s+=a.A[i];
    }
    return s;
}

float Avg(struct Array a)
{
    return (float)sum(a)/a.length;
}

void Reverse(struct Array &a)
{
    int b[a.length];
    for(int i=0,j=a.length-1;j>=0;i++,j--)
    {
        b[i]=a.A[j];
    }
    for(int i=0;i<a.length;i++)
    {
        a.A[i]=b[i];
    }
}

void Reverse2(struct Array &a)
{
    for(int i=0,j=a.length-1;i<j;i++,j--)
    {
        /*int temp=a.A[i];
        a.A[i]=a.A[j];
        a.A[j]=temp;*/
        swap(a.A[i],a.A[j]);
    }
}

void LeftShift(struct Array &a)
{
    for(int i=0;i<a.length-1;i++)
    {
        a.A[i]=a.A[i+1];
    }
    a.A[a.length-1]=0;
}

void LeftRotate(struct Array &a)
{
    int x=a.A[0];
    for(int i=0;i<a.length-1;i++)
    {
        a.A[i]=a.A[i+1];
    }
    a.A[a.length-1]=x;
}

void RightShift(struct Array &a)
{
    for(int i=a.length-1;i>0;i--)
    {
        a.A[i]=a.A[i-1];
    }
    a.A[0]=0;
}

void RightRotate(struct Array &a)
{
    int x=a.A[a.length-1];
    for(int i=a.length-1;i>0;i--)
    {
        a.A[i]=a.A[i-1];
    }
    a.A[0]=x;
}

void InsertSort(struct Array &a,int x)
{
    int i=a.length-1;
    if(a.length==a.sz)
    {
        return;//No space to push forward
    }
    while(i>=0 && a.A[i]>x)
    {
        a.A[i+1]=a.A[i];
        i--;
    }
    a.A[i+1]=x;
    a.length++;
}

bool isSorted(struct Array a)
{
    for(int i=0;i<a.length-1;i++)
    {
        if(a.A[i]>a.A[i+1])
            return false;
    }
    return true;
}

void Rearrange(struct Array &a)
{
    int i=0;
    int j=a.length-1;
    while(i<j)
    {
       while(a.A[i]<0)
       {
          i++;
       }
       while(a.A[j]>=0)
       {
          j--;
       }
       if(i<j)
       {
           swap(a.A[i],a.A[j]);
       }
    }

}

struct Array* Merge(struct Array a,struct Array b)
{
    int i,j,k;
    struct Array *c=new struct Array();
    c->length=a.length+b.length;
    c->sz=20;
    c->A=new int[c->sz];
    i=j=k=0;
    while(i<a.length && j<b.length)
    {
        if(a.A[i]<b.A[j])
        {
            c->A[k]=a.A[i];
            k++;
            i++;
        }
        else
        {
            c->A[k]=b.A[j];
            k++;
            j++;
        }
    }
    for(;i<a.length;i++)
    {
        c->A[k]=a.A[i];
        k++;
    }
    for(;j<b.length;j++)
    {
        c->A[k]=b.A[j];
        k++;
    }
    return c;
}

struct Array* UnsortedUnion(struct Array a,struct Array b)
{
    int k=0;
    struct Array *c=new struct Array();
    c->sz=a.sz+b.sz;
    c->A=new int[c->sz];
    for(int i=0;i<a.length;i++)
    {
        c->A[k]=a.A[i];
        k++;
    }
    for(int j=0;j<b.length;j++)
    {
        bool f=true;
        for(int l=0;l<=k;l++)
        {
            if(c->A[l]==b.A[j])
            {
                f=false;
            }
        }
        if(f)
        {
            c->A[k]=b.A[j];
            k++;
        }
    }
    c->length=k;
    return c;
};

struct Array* SortedUnion(struct Array a,struct Array b)
{
    int i,j,k;
    struct Array *c=new struct Array();
    c->sz=20;
    c->A=new int[c->sz];
    i=j=k=0;
    while(i<a.length && j<b.length)
    {
        if(a.A[i]==b.A[j])
        {
            c->A[k]=a.A[i];
            i++;
            j++;
            k++;
        }
        else if(a.A[i]<b.A[j])
        {
            c->A[k]=a.A[i];
            k++;
            i++;
        }
        else
        {
            c->A[k]=b.A[j];
            k++;
            j++;
        }
    }
    for(;i<a.length;i++)
    {
        c->A[k]=a.A[i];
        k++;
    }
    for(;j<b.length;j++)
    {
        c->A[k]=b.A[j];
        k++;
    }
    c->length=k;
    return c;
}

struct Array * UnsortedIntersection(struct Array a,struct Array b)
{
    int k=0;
    struct Array *c=new struct Array();
    c->sz=a.sz+b.sz;
    c->A=new int[c->sz];
    for(int i=0;i<a.length;i++)
    {
        for(int j=0;j<b.length;j++)
        {
            if(a.A[i]==b.A[j])
            {
                c->A[k]=a.A[i];
                k++;
            }
        }
    }
    c->length=k;
    return c;
};

struct Array* SortedIntersection(struct Array a,struct Array b)
{
    int i,j,k;
    struct Array *c=new struct Array();
    c->sz=20;
    c->A=new int[c->sz];
    i=j=k=0;
    while(i<a.length && j<b.length)
    {
        if(a.A[i]==b.A[j])
        {
            c->A[k]=a.A[i];
            i++;
            j++;
            k++;
        }
        else if(a.A[i]<b.A[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    c->length=k;
    return c;
}

struct Array* UnsortedDifference(struct Array a,struct Array b)
{
    int k=0;
    struct Array *c=new struct Array();
    c->sz=a.sz;
    c->A=new int[c->sz];
    for(int i=0;i<a.length;i++)
    {
        bool flag=true;
        for(int j=0;j<b.length;j++)
        {
            if(a.A[i]==b.A[j])
            {
                flag=false;
            }
        }
        if(flag)
        {
            c->A[k]=a.A[i];
            k++;
        }
    }
    c->length=k;
    return c;
};

struct Array* SortedDifference(struct Array a,struct Array b)
{
    int i,j,k;
    struct Array *c=new struct Array();
    c->sz=20;
    c->A=new int[c->sz];
    i=j=k=0;
    while(i<a.length && j<b.length)
    {
        if(a.A[i]==b.A[j])
        {
            c->A[k]=a.A[i];
            i++;
            j++;
        }
        else if(a.A[i]<b.A[j])
        {
            c->A[k]=a.A[i];
            k++;
            i++;
        }
        else
        {
            j++;
        }
    }
    for(;i<a.length;i++)
    {
        c->A[k]=a.A[i];
        k++;
    }
    c->length=k;
    return c;
}

bool SetMembership(struct Array a,int key)
{
    for(int i=0;i<a.length;i++)
    {
        if(key==a.A[i])
        {
            return true;
        }
    }
    return false;
}
int main()
{
    cout << "Array ADT " << endl;
    struct Array arr1,arr2;
    cout<<"For First Array: "<<endl;
    cout<<"Enter size of array: "<<endl;
    cin>>arr1.sz;

    arr1.A=new int[arr1.sz];

    arr1.length=0;//As no element in an array

    int n;
    cout<<"Enter how many elements to enter: "<<endl;
    cin>>n;

    cout<<"Enter all Elements: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr1.A[i];
        arr1.length++;
    }

    //Array 2
    cout<<"For Second Array: "<<endl;
    cout<<"Enter size of array: "<<endl;
    cin>>arr2.sz;

    arr2.A=new int[arr2.sz];

    arr2.length=0;//As no element in an array

    int n1;
    cout<<"Enter how many elements to enter: "<<endl;
    cin>>n1;

    cout<<"Enter all Elements: "<<endl;
    for(int i=0;i<n1;i++)
    {
        cin>>arr2.A[i];
        arr2.length++;
    }

    Display(arr1);
    Display(arr2);
    /*struct Array *arr3=SortedDifference(arr1,arr2);
    cout<<"Elements of merged Array 3: ";
    for(int i=0;i<arr3->length;i++)
    {
        cout<<arr3->A[i]<<" ";
    }
    cout<<endl;*/


    //MENU for All the Functions
    int choice;
    do
    {
        struct Array *arr3;
       cout<<"***** MENU *****"<<endl;
    cout<<"1.Insert"<<endl;
    cout<<"2.Append"<<endl;
    cout<<"3.Linear Search"<<endl;
    cout<<"4.Linear Search with transposition"<<endl;
    cout<<"5.Linear Search Back to front"<<endl;
    cout<<"6.Binary Search"<<endl;
    cout<<"7.Recursive Binary Search"<<endl;
    cout<<"8.Delete"<<endl;
    cout<<"9.Get element at index"<<endl;
    cout<<"10.Set element at index"<<endl;
    cout<<"11.Maximum"<<endl;
    cout<<"12.Minimum"<<endl;
    cout<<"13.Sum"<<endl;
    cout<<"14.Average"<<endl;
    cout<<"15.Reverse"<<endl;
    cout<<"16.Reverse 2"<<endl;
    cout<<"17.Left Shift"<<endl;
    cout<<"18.Left Rotate"<<endl;
    cout<<"19.Right Shift"<<endl;
    cout<<"20.Right Rotate"<<endl;
    cout<<"21.Insert in sorted Array"<<endl;
    cout<<"22.Check whether Array is Sorted"<<endl;
    cout<<"23.Rearrange -ve on Left side"<<endl;
    cout<<"24.Merge two Arrays"<<endl;
    cout<<"25.Union for Unsorted Arrays"<<endl;
    cout<<"26.Union for Sorted Arrays"<<endl;
    cout<<"27.Intersection for Unsorted Arrays"<<endl;
    cout<<"28.Intersection for Sorted Arrays"<<endl;
    cout<<"29.Difference of Unsorted Arrays"<<endl;
    cout<<"30.Difference of Sorted Arrays"<<endl;
    cout<<"31.Set Membership"<<endl;
    cout<<"32.Display Arrays"<<endl;
    cout<<"33.Quit"<<endl;

    cout<<endl<<"Enter your Choice:"<<endl;
    cin>>choice;

    switch(choice)
    {
    case 1:
        int index,x;
        cout<<"Enter index and number:"<<endl;
        cin>>index>>x;
        Insert(arr1,index,x);
        cout<<"Insertion done."<<endl;
        break;
    case 2:
        int x1;
        cout<<"Enter number:"<<endl;
        cin>>x1;
        Append(arr1,x1);
        cout<<"Appending Done."<<endl;;
        break;
    case 3:
        int key;
        cout<<"Enter Number:"<<endl;
        cin>>key;
        cout<<"Entered Number is at index "<<LinearSearch(arr1,key)<<endl;
        break;
    case 4:
        int key1;
        cout<<"Enter Number:"<<endl;
        cin>>key1;
        cout<<"Entered Number is at index "<<TranspositionLinearSearch(arr1,key1)<<endl;
        break;
    case 5:
        int key2;
        cout<<"Enter Number:"<<endl;
        cin>>key2;
        cout<<"Entered Number is at index "<<BackToFrontLinearSearch(arr1,key2)<<endl;
        break;
    case 6:
        int key4;
        cout<<"Enter Number:"<<endl;
        cin>>key4;
        cout<<"Entered Number is at index "<<BinarySearch(arr1,key)<<endl;
        break;
    case 7:
        int key3;
        cout<<"Enter Number:"<<endl;
        cin>>key3;
        cout<<"Entered Number is at index "<<RBinarySearch(0,arr1.length,arr1,key3)<<endl;
        break;
    case 8:
        int x2;
        cout<<"Enter the element to be Deleted:"<<endl;
        cin>>x2;
        if(Delete(arr1,LinearSearch(arr1,x2))!=-1)
        {
            cout<<"Element Deleted."<<endl;
        }
        else{
            cout<<"Element not present"<<endl;
        }
        break;
    case 9:
        int index1;
        cout<<"Enter index:"<<endl;
        cin>>index1;
        cout<<"Element at "<<index<<" is "<<Get(arr1,index)<<endl;
        break;
    case 10:
        int index2,x5;
        cout<<"Enter index and number:"<<endl;
        cin>>index2>>x5;
        Set(arr1,index2,x5);
        cout<<x<<" set at "<<index2<<endl;
        break;
    case 11:
        cout<<"Maximum in the Array is "<<Max(arr1)<<endl;
        break;
    case 12:
        cout<<"Minimum in the Array is "<<Min(arr1)<<endl;
        break;
    case 13:
        cout<<"Sum of all the elements in the Array is "<<sum(arr1)<<endl;
        break;
    case 14:
        cout<<"Average of all the elements in the Array is "<<Avg(arr1)<<endl;
        break;
    case 15:
        Reverse(arr1);
        cout<<"Reversed Array: "<<endl;
        Display(arr1);
        break;
    case 16:
        Reverse2(arr1);
        cout<<"Reversed Array: "<<endl;
        Display(arr1);
        break;
    case 17:
        LeftShift(arr1);
        cout<<"Left Shifted Array: "<<endl;
        Display(arr1);
        break;
    case 18:
        LeftRotate(arr1);
        cout<<"Left Rotated Array: "<<endl;
        Display(arr1);
        break;
    case 19:
        RightShift(arr1);
        cout<<"Right Rotated Array: "<<endl;
        Display(arr1);
        break;
    case 20:
        RightRotate(arr1);
        cout<<"Right Rotated Array: "<<endl;
        Display(arr1);
        break;
    case 21:
        int x6;
        cout<<"Enter the number to be inserted: "<<endl;
        InsertSort(arr1,x6);
        cout<<"Element inserted."<<endl;
        break;
    case 22:
        {bool f1=isSorted(arr1);
        if(f1)
        {
            cout<<"Array Sorted"<<endl;
        }
        else
        {
            cout<<"Array not Sorted"<<endl;
        }
        break;}
    case 23:
        Rearrange(arr1);
        cout<<"Rearranged Array:"<<endl;
        Display(arr1);
        break;
    case 24:
        arr3=Merge(arr1,arr2);
        cout<<"Elements of merged Array: ";
        for(int i=0;i<arr3->length;i++)
        {
            cout<<arr3->A[i]<<" ";
        }
        cout<<endl;
        break;
    case 25:
        arr3=UnsortedUnion(arr1,arr2);
        cout<<"Elements of Union of Array: ";
        for(int i=0;i<arr3->length;i++)
        {
            cout<<arr3->A[i]<<" ";
        }
        cout<<endl;
        break;
    case 26:
        arr3=SortedUnion(arr1,arr2);
        cout<<"Elements of Union of Array: ";
        for(int i=0;i<arr3->length;i++)
        {
            cout<<arr3->A[i]<<" ";
        }
        cout<<endl;
        break;
    case 27:
        arr3=UnsortedIntersection(arr1,arr2);
        cout<<"Elements of Intersection of Array: ";
        for(int i=0;i<arr3->length;i++)
        {
            cout<<arr3->A[i]<<" ";
        }
        cout<<endl;
        break;
    case 28:
        arr3=SortedIntersection(arr1,arr2);
        cout<<"Elements of Intersection of Array: ";
        for(int i=0;i<arr3->length;i++)
        {
            cout<<arr3->A[i]<<" ";
        }
        cout<<endl;
        break;
    case 29:
        arr3=UnsortedDifference(arr1,arr2);
        cout<<"Elements of Difference of Array: ";
        for(int i=0;i<arr3->length;i++)
        {
            cout<<arr3->A[i]<<" ";
        }
        cout<<endl;
        break;
    case 30:
        arr3=SortedDifference(arr1,arr2);
        cout<<"Elements of Difference of Array: ";
        for(int i=0;i<arr3->length;i++)
        {
            cout<<arr3->A[i]<<" ";
        }
        cout<<endl;
        break;
    case 31:
        {int x10;
        cout<<"Enter the number:"<<endl;
        cin>>x10;
        bool f=SetMembership(arr1,x);
        if(f)
        {
            cout<<x<<" member of Array"<<endl;
        }
        else
        {
            cout<<x<<" Not a member of Array"<<endl;
        }
        break;}
    case 32:
        Display(arr1);
        Display(arr2);
        break;
    }

    cout<<endl;
    }while(choice!=33);

    cout<<"!!Thankyou!!"<<endl;

    return 0;
}

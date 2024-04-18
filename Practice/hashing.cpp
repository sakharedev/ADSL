#include <iostream>

class hashing
{
    int hashtable[11],key;
   
public:
    hashing()
        {
            for(int i=0;i<11;i++)
              hashtable[i]=-1;
           
        }
       
        int hashFns(int key)
        {
            return key%11;
           
        }
       
  void  linearProblingWithoutReplace()
    {
        std::cout<<"Enter Key to be inserted in hash table";
        std::cin>>key;
        int hadd =hashFns(key);
        if(hashtable[hadd]==-1)
            hashtable[hadd]=key;
        else
        {
            int j=hadd+1;
            while(hashtable[j]!=-1 && j!=hadd)
            {
                j=(j+1)%11;
            }
            hashtable[j]=key;
        }
           
    }
   
    int searchHash(int key)
    {
        int hadd=hashFns(key);
        if(hashtable[hadd]==key)
        {
            std::cout<<"found at location :: "<<hadd;
            return 1;
        }
        else
        {
            int j =hadd+1;
            while(j!=hadd && hashtable[j]!=-1)
            {  
                if(hashtable[j]==key)
                {
                     std::cout<<"found at location :: "<<j;
                    return 1;
                }
                j=(j+1)%11;
            }
             std::cout<<"not found ";
            return 0;
        }
    }
    void displayTable()
    {
        for(int i=0;i<11;i++)
         std::cout<<hashtable[i]<<std::endl;
    }
};

int main()
{
   hashing h1;
   h1.linearProblingWithoutReplace();
    h1.linearProblingWithoutReplace();
 h1.linearProblingWithoutReplace();
  h1.linearProblingWithoutReplace();
   h1.linearProblingWithoutReplace();
   h1.displayTable();
   h1.searchHash(67);
   
    return 0;
}
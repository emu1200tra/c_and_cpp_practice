#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
string LCS_2(string s1,string s2)
{
    if(s1==""||s2=="")
        return "";
    size_t m=s1.size()+1;
    size_t n=s2.size()+1;
    int lcs[100][100];
    size_t i,j;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            lcs[i][j]=0;
    for(i=1;i<m;i++)
        for(j=1;j<n;j++)
        {
            if(s1[i-1]==s2[j-1])
                lcs[i][j]=lcs[i-1][j-1]+1;
            else
                lcs[i][j]=lcs[i-1][j]>=lcs[i][j-1]?lcs[i-1][j]:lcs[i][j-1];
        }
        i=m-2;
        j=n-2;
        string ss="";
        string ans="";
        while(i!=-1&&j!=-1)
        {
            if(s1[i]==s2[j])
            {
                ss+=s1[i];
                i--;
                j--;
            }
            else
            {
                if(lcs[i+1][j+1]==lcs[i][j])
                {
                    i--;
                    j--;
                }
                else
                {
                    if(lcs[i][j+1]>=lcs[i+1][j])
                        i--;
                    else
                        j--;
                }
            }
        }
        reverse(ss.begin(),ss.end());
        return ss;
}

int main(){
    string s1,s2;
    cout<<"Please input sequence1¡G";
    cin>>s1;
    cout<<"Please input sequence2¡G";
    cin>>s2;
    cout<<endl;
    //while(cin>>s1>>s2)
    //{
        cout<<"The LCS :"+LCS_2(s1,s2)<<endl;
        system("PAUSE");
    //}
    return 0;
}

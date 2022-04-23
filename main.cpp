#include <iostream>
#include <cstring>
using namespace std;
class big
{
    int decint;
    string strint;
public:
    big()
    {
        decint=0;
        strint="";
    }
    big(string s)
    {
        strint=s;
    }
    big(int decint)
    {
        strint=to_string(decint);
    }
    big operator +(big& b)
    {
        big a;
        string sum;
        char mod;
        long long r,y,x=0,cnt=0,n=0;
        bool negative1,negative2,first,second=false;
        if(this->strint[0]=='-')
        {
            this->strint.erase(0,1);
            negative1=true;
            n++;
        }
        if(b.strint[0]=='-')
        {
            b.strint.erase(0,1);
            negative2=true;
            n++;
        }
        while((this->strint.size()-1)>(b.strint.size()-1))
        {
            b.strint='0'+ b.strint;
        }
        while((this->strint.size()-1)<(b.strint.size()-1))
        {
            this->strint='0'+this->strint;
        }

        if(n==2)
        {
            for(int i=strint.size()-1; i>=0; i--)
            {
                sum="";
                mod=0;
                if(i==strint.size()-1)
                    sum=to_string((this->strint[i]-'0')+(b.strint[i]-'0'));
                else
                    sum=to_string((r)+(b.strint[i]-'0'));
                if(sum.size()>1)
                {
                    a.strint=sum[sum.size()-1]+a.strint;
                    mod=sum[0]-'0';
                }
                else
                    a.strint=sum+a.strint;

                if(mod!=0)
                {
                    r=(this->strint[i-1]-'0')+mod;
                }
                else
                    r=this->strint[i-1]-'0';

                if(i==0 && mod!=0)
                {
                    a.strint=to_string(mod)+a.strint;
                }
            }
            a.strint='-'+a.strint;
        }
        else if(n==1)
        {
            if((this->strint[0]-'0')==(b.strint[0]-'0'))
            {
                while(x!=this->strint.size()-1)
                {
                    if((this->strint[x]-'0')>(b.strint[x]-'0'))
                    {
                        first=true;
                        break;
                    }
                    else if((this->strint[x]-'0')<(b.strint[x]-'0'))
                    {
                        second=true;
                        break;
                    }
                    x++;
                }
                if(x==this->strint.size()-1 && negative1)
                {
                    a.strint='0';
                    return a;
                }
            }
            else
            {
                if((this->strint[0]-'0')>(b.strint[0]-'0'))
                {
                    first=true;
                }
                else if((this->strint[0]-'0')<(b.strint[0]-'0'))
                    second=true;
            }
            if(first && !second)
            {
                r=this->strint[strint.size()-1]-'0';
                for(int i=strint.size()-1; i>=0; i--)
                {
                    sum="";
                    if((r)>=(b.strint[i]-'0'))
                    {
                        if(i==strint.size()-1)
                        {
                            sum=to_string((this->strint[i]-'0')-(b.strint[i]-'0'));
                        }
                        else
                            sum=to_string((r)-(b.strint[i]-'0'));
                        r=this->strint[i-1]-'0';
                    }
                    else
                    {
                        if(i==strint.size()-1)
                        {
                            y=(this->strint[i]-'0')+10;
                        }
                        else
                        {
                            y=r+10;
                        }
                        sum=to_string((y)-(b.strint[i]-'0'));
                         r=(this->strint[i-1]-'0')-1;
                    }


                    a.strint=sum+a.strint;
                }
                for(int i=0; i<a.strint.size()-1; i++)
                {
                    if(a.strint[i]-'0'==0)
                    {
                        cnt++;
                    }
                    else
                        break;
                }
                a.strint.erase(0,cnt);
                if(negative1 && !negative2)
                    a.strint='-'+a.strint;
            }
            else if(second && !first)
            {
                r=b.strint[strint.size()-1]-'0';
                for(int i=strint.size()-1; i>=0; i--)
                {
                    sum="";
                    if((r)>=(this->strint[i]-'0'))
                    {
                        if(i==strint.size()-1)
                        {
                            sum=to_string((b.strint[i]-'0')-(this->strint[i]-'0'));
                        }
                        else
                            sum=to_string((r)-(this->strint[i]-'0'));
                        r=b.strint[i-1]-'0';
                    }
                    else
                    {
                        if(i==strint.size()-1)
                        {
                            y=(b.strint[i]-'0')+10;
                        }
                        else
                            y=r+10;

                        sum=to_string((y)-(this->strint[i]-'0'));
                        r=(b.strint[i-1]-'0')-1;
                    }

                    a.strint=sum+a.strint;
                }
                if(!negative1 && negative2)
                    a.strint='-'+a.strint;
            }
        }
        else if(n==0)
        {
            for(int i=strint.size()-1; i>=0; i--)
            {
                sum="";
                mod=0;
                if(i==strint.size()-1)
                    sum=to_string((this->strint[i]-'0')+(b.strint[i]-'0'));
                else
                    sum=to_string((r)+(b.strint[i]-'0'));
                if(sum.size()>1)
                {
                    a.strint=sum[sum.size()-1]+a.strint;
                    mod=sum[0]-'0';
                }
                else
                    a.strint=sum+a.strint;

                if(mod!=0)
                {
                    r=(this->strint[i-1]-'0')+mod;
                }
                else
                    r=this->strint[i-1]-'0';

                if(i==0 && mod!=0)
                {
                    a.strint=to_string(mod)+a.strint;
                }
            }
        }
        return a;
    }
    big& operator =(const big& a)
    {
        this->strint=a.strint;
        return *this;
    }
    int size()
    {
        if(this->strint[0]=='-')
        {
            return this->strint.size()-1;
        }
        return this->strint.size();
    }

    friend ostream& operator <<(ostream&,big&);
};
ostream& operator <<(ostream& out,big& b)
{
    out<<b.strint;
    return out;
}
int main()
{
    big c("999");
    big d("-85421");
    big m ;
    m = c + d;
    cout<<m<<endl;
    cout<<m.size();
    return 0;
}

#include <iostream>
#include "CImg.h"
#include "limits.h"
using namespace cimg_library;
using namespace std;

int a[8][8],v;
// create image size 500x500x1,3 channels (RGB) default colour white
CImg<unsigned char>  myImage(500,500,1,3,200);
const unsigned char red[] = { 255,0,0 },black[] = { 0,0,0 },white[] = { 255,255,255 };

 CImg<unsigned char> initialize(CImg<unsigned char>  myImage)
{
    int p,q,r,s,n,o; 
    for(n=0;n<8;n++)
    {
        for(o=0;o<8;o++)
        {
          a[n][o]=0;  
        }
    }
    a[3][3]=1;
    a[4][4]=1;
    a[3][4]=2;
    a[4][3]=2;
    for(p=50,q=50,r=450,s=50;q<=450,s<=450;q=q+50,s=s+50)
    {
         myImage.draw_line(p,q,r,s,red);
    }
    for(p=50,q=50,r=50,s=450;p<=450,r<=450;p=p+50,r=r+50)
    {
        myImage.draw_line(p,q,r,s,red);
    }
    myImage.draw_circle(225,225,10,black);
    myImage.draw_circle(275,225,10,white);        
    myImage.draw_circle(225,275,10,white);
    myImage.draw_circle(275,275,10,black);
    return myImage;
} 
void process_move(int n,int o,int user)
{
    int l,m,u,s;
    v=0;
    //upward
    for(l=1;l<n+1;l++)
    {
        if(a[n-l][o]!=user%2+1)
        {
            break;
        }
    }
    if(a[n-l][o]==user && l!=n+1&&a[n-1][o]!=user)
    {
        v=1;
        for(m=1;m<l;m++)
        {
                    
                a[n-m][o]=user;
                if(user==1)
                    myImage.draw_circle(75+50*(n-m),75+50*(o),10,black);
                else
                    myImage.draw_circle(75+50*(n-m),75+50*(o),10,white);
                    
        }
    }

    //leftward  
    for(u=1;u<o+1;u++)
    {
        if(a[n][o-u]!=user%2+1)
        {
            break;
        }
    }
    if(u!=o+1&&a[n][o-u]==user&&a[n][o-1]!=user)
    {
       v=1;
        for(s=1;s<u;s++)
        {
                
               a[n][o-s]=user;
                if(user==1)
                    myImage.draw_circle(75+50*(n),75+50*(o-s),10,black);
                else
                    myImage.draw_circle(75+50*(n),75+50*(o-s),10,white);
             
        }   
    }
    //downward
    for(l=1;l<8-n;l++)
    {
        if(a[n+l][o]!=user%2+1)
        {
            break;
        }
    }
    if(l!=8-n && a[n+l][o]==user && a[n+1][o]!=user)
    {
        v=1;
        for(m=1;m<l;m++)
        {
                a[n+m][o]=user;
                if(user==1)
                    myImage.draw_circle(75+50*(n+m),75+50*(o),10,black);
                else
                    myImage.draw_circle(75+50*(n+m),75+50*(o),10,white);    
        }
    }
    //rightward
    for(u=1;u<8-o;u++)
    {
        if(a[n][o+u]!=user%2+1)
        {
            break;
        }
    }
    if(u!=8-o&&a[n][o+u]==user&&a[n][o+1]!=user)
    {
        v=1;
        for(s=1;s<u;s++)
        {
                a[n][o+s]=user;
                if(user==1)
                    myImage.draw_circle(75+50*(n),75+50*(o+s),10,black);
                else
                    myImage.draw_circle(75+50*(n),75+50*(o+s),10,white);
             
        }
    }    
    //upleft
    for(l=1,u=1;l<n+1&&u<o+1;l++,u++)
    {
        if(a[n-l][o-u]!=user%2+1)
        {
            break;
        }
    }
    if(l!=n+1&&u!=o+1&&a[n-l][o-u]==user&&a[n-1][o-1]!=user)
    {
        v=1;
        for(m=1,s=1;m<l;m++,s++)
        {
                a[n-m][o-s]=user;
                if(user==1)
                    myImage.draw_circle(75+50*(n-m),75+50*(o-s),10,black);
                else
                    myImage.draw_circle(75+50*(n-m),75+50*(o-s),10,white);
             
        }
    }
    //upright
    for(l=1,u=1;l<n+1||u<8-o;l++,u++)
    {
        if(a[n-l][o+u]!=user%2+1)
        {
            break;
        }
    }
    if(l!=n+1&&u!=8-o&&a[n-l][o+u]==user&&a[n-1][o+1]!=user)
    {
        v=1;
        for(m=1,s=1;m<l;m++,s++)
        {
                a[n-m][o+s]=user;
                if(user==1)
                    myImage.draw_circle(75+50*(n-m),75+50*(o+s),10,black);
                else
                    myImage.draw_circle(75+50*(n-m),75+50*(o+s),10,white);
             
        }
    }
    
    //downleft
    for(l=1,u=1;l<8-n||u<o+1;l++,u++)
    {
        if(a[n+l][o-u]!=user%2+1)
        {
            break;
        }
    }
    if(l!=8-n&&u!=o+1&&a[n+l][o-u]==user&&a[n+1][o-1]!=user)
    {
        v=1;
        for(m=1,s=1;m<l;m++,s++)
        {
            a[n+m][o-s]=user;
            if(user==1)
                myImage.draw_circle(75+50*(n+m),75+50*(o-s),10,black);
            else
                myImage.draw_circle(75+50*(n+m),75+50*(o-s),10,white); 
        }
    }
    //downright
    for(l=1,u=1;l<8-n||u<8-o;l++,u++)
    {
        if(a[n+l][o+u]!=user%2+1)
        {
            break;
        }
    }
    if(l!=8-n&&u!=8-o&&a[n+l][o+u]==user&&a[n+1][o+1]!=user)
    {
        v=1;
        for(m=1,s=1;m<l;m++,s++)
        { 
                a[n+m][o+s]=user;
                if(user==1)
                    myImage.draw_circle(75+50*(n+m),75+50*(o+s),10,black);
                else
                    myImage.draw_circle(75+50*(n+m),75+50*(o+s),10,white); 
        }
    }
}

int main()
{
    int p,q,r,s,l,player,m,n,o,x,y;
    myImage= initialize(myImage);
    CImgDisplay main_disp(myImage); // display it
    player=0;
    while (!main_disp.is_closed()) 
    {
        main_disp.wait();
        if (main_disp.button()&1 && main_disp.mouse_y()>50 && main_disp.mouse_x()>50 && main_disp.mouse_x()<450 && main_disp.mouse_y()<450)
        {
            main_disp.set_button();
            const int y=main_disp.mouse_y(),x=main_disp.mouse_x();
            l=50*(x/50)+25;
            m=50*(y/50)+25;
            n=((50*(x/50)+25)/50)-1;
            o=((50*(y/50)+25)/50)-1;
            process_move(n,o,player%2+1);
            if(player%2==0)
            {
                if(v==1)
                {
                    a[n][o]=1;
                    myImage.draw_circle(l,m,10,black);
                    player++;
                }
            }
            else
            {
                if(v==1)
                {
                    a[n][o]=2;
                    myImage.draw_circle(l,m,10,white);
                    player++;
                }
            }
            main_disp.display(myImage);
        }
    }
}

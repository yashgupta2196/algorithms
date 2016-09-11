import java.util.*;
class cows_bulls
{
    static Scanner sc=new Scanner(System.in);
    static String num="",guess="";
    static int cows=0,bulls=0;
    void generate()
    {
        double a=0.0;
        for(int i=1;i<=4;i++)
        {
            int f=0;
            a=Math.random();
            String s=Double.toString(a);
            char ch=s.charAt(10);
            if(i==1&&ch=='0')
            {
                f=1;
            }
            for(int l=0;l<=i-2;l++)
            {
                if(ch==num.charAt(l))
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            num=num+ch;
            else
            {
                i--;
                f=0;
                continue;
            }
        }
        System.out.println(num);
    }
    void accept()
    {
        System.out.println("Enter your guess...");
        guess=sc.nextLine();
    }
    void check()
    {
        if(guess.equals(num))
        {
            cows=-1;
            bulls=-1;
            return;
        }
        cows=0;
        bulls=0;
        for(int i=0;i<4;i++)
        {
            char cg=guess.charAt(i);
            for(int j=0;j<4;j++)
            {
                char cn=num.charAt(j);
                if(cn==cg)
                {
                    if(i==j)
                    bulls++;
                    else
                    cows++;
                }
            }
        }
    }
    public static void main()
    {
        cows_bulls ob=new cows_bulls();
        ob.generate();
        int i=1;
        do
        {
            ob.accept();
            ob.check();
            if(cows==-1&&bulls==-1)
            {
                System.out.println("Congratulations!!! You win!!! The number is "+num+".");
                break;
            }
            System.out.println(cows+" Cows and "+bulls+" Bulls");
            i++;
            if(i==11)
            System.out.println("You lose...Better luck next time!!!");
        }
        while(i<=10);
    }
}
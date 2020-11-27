using System;
using System.Text;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using static System.Console;
using static System.Math;

namespace Test
{
    public class Program
    {
        public static void Main(string[] args)
        {
            new Program().solve();
        }

        public void solve()
        {
            int a = int.Parse(ReadLine()); 

            int ans = 0;
            for(var i=1; i<=a; i++){
                if(i%2==1 && yakusu(i)==8) {
                    ans++;
                }
            }
            WriteLine(ans);

        }

        static int yakusu(int n){
            int ans = 0;
            int i=1;
            while(i<=n){
                if(n%i++==0)ans++;
            }
            return ans;
        }

    }
}
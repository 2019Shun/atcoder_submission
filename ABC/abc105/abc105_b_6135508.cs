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
            int n = int.Parse(ReadLine());
            if(dfs(n)) WriteLine("Yes");
            else WriteLine("No");
        }

        static bool dfs(int total){
            if(total==0) return true;
            if(total<0) return false;
            return dfs(total-4) || dfs(total-7);
        }
    }
}
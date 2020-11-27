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
            var CinTemp = ReadLine().Split(' ');
            int a = int.Parse(CinTemp[0]);
            int b = int.Parse(CinTemp[1]);
            if(a <= 5) WriteLine(0);
            else if(a <= 12) WriteLine(b/2);
            else WriteLine(b);
        }
    }
}
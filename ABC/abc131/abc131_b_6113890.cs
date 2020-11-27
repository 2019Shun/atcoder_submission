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
            new Program().abc131_b();
        }

        public void abc131_b()
        {
            var CinTemp = ReadLine().Split(' ');
            int a = int.Parse(CinTemp[0]);
            int b = int.Parse(CinTemp[1]);
            int ans = 100000;
            int total = 0;
            for (int i = 0; i < a; i++)
            {
                total += b+i;
                ans = Abs(ans) > Abs(b+i) ? b+i : ans;
            }
            WriteLine(total-ans);
        }
    }
}
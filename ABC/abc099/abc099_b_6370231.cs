using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using static System.Math;

namespace Practice
{
    class Program
    {
        static void Main(string[] args)
        {
            new Program().abc99_b();
        }

        public void Solve()
        {

            string s = Console.ReadLine();
            bool Flag = true;
            bool Cflag = false;
            for (int i = 0; i < s.Length; i++)
            {
                if (i == 0)
                {
                    if (s[0] != 'A') Flag = false;
                }
                else if(2 <= i && i < s.Length - 1)
                {
                    if (('a' <= s[i] && s[i] <= 'z'))
                    {
                        continue;
                    }
                    else if(s[i] == 'C' && Cflag==false)
                    {
                        Cflag = true;
                        continue;
                    }

                    Flag = false;
                }
                else
                {
                    if (('a' <= s[i] && s[i] <= 'z')) continue;
                    Flag = false;
                }
            }

            if (Flag && Cflag) Console.WriteLine("AC");
            else Console.WriteLine("WA");
        }

        public void abc102_b()
        {
            int n = int.Parse(Console.ReadLine());

            List<int> a = Console.ReadLine().Split().Select(int.Parse).ToList();

            Int32 Amax = 0;
            Int32 Amin = Int32.MaxValue;

            for (int i = 0; i < n; i++)
            {
                Amax = Math.Max(Amax, a[i]);
                Amin = Math.Min(Amin, a[i]);
            }

            Console.WriteLine(Amax - Amin);
        }

        public void abc100_b()
        {

            var l = Console.ReadLine().Split(' ');
            int d = int.Parse(l[0]);
            int n = int.Parse(l[1]);
            int ans = 0;
            int num = 0;
            while (true)
            {
                int t = ++ans;
                int wn = 0;
                while(t % 100 == 0)
                {
                    t /= 100;
                    wn++;
                }
                if(wn == d)
                {
                    if(++num == n)
                    {
                        break;
                    }
                }
            }
            WriteLine(ans);
        }

        public void abc99_b()
        {
            var l = Console.ReadLine().Split(' ');
            int a = int.Parse(l[0]);
            int b = int.Parse(l[1]);
            int t = 0;
            for (int i = 1; i < b-a; i++)
            {
                t += i;
            }
            WriteLine(t - a);
        }
    }

}

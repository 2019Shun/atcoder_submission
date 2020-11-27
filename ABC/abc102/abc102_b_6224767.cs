using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Practice
{
    class Program
    {
        static void Main(string[] args)
        {
            new Program().abc102_b();
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
    }

}

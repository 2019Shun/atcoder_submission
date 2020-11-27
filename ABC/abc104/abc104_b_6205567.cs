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
            new Program().Solve();
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
    }

}

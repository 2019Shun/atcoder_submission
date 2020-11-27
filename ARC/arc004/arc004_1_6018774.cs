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
            // new Program().abc127_b(new ConsoleInput(Console.In, ' '));
            new Program().arc4_a();
        }

        // public void abc127_b(ConsoleInput cin)
        // {
        //     var r = cin.ReadInt;
        //     var D = cin.ReadInt;
        //     var x = cin.ReadInt;

        //     var xi = new List<int> {x};

        //     for(int i = 1; i < 11; i++){
        //         xi.Add(r * xi[i-1] - D);
        //         WriteLine(xi[i]);
        //     }
        // }

        // public void abc69_a(){
        //     var CinTemp = ReadLine().Split(' ');
        //     int n = int.Parse(CinTemp[0]);
        //     int m = int.Parse(CinTemp[1]);
            
        //     WriteLine((n-1)*(m-1));
        // }
        
        public void arc4_a(){
            int n = int.Parse(ReadLine());
            // int[] x = new int[n];
            // int[] y = new int[n];
            List<int> x = new List<int>(n);
            List<int> y = new List<int>(n);
            for(var i = 0; i < n; i++){
                var CinTemp = ReadLine().Split(' ');
                x.Add(int.Parse(CinTemp[0]));
                y.Add(int.Parse(CinTemp[1]));   
            }

            int ans = 0;
            for(var i = 0; i < n; i++){
                for(var j = 0; j < n; j++){
                    if(i==j)continue;
                    ans = Max(ans, (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                }
            }
            WriteLine(Sqrt(ans));
        }
    }
}
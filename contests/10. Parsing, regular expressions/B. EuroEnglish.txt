using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace ConsoleApplication5
{
    class Program
    {
        static void del(ref string s, int n, int k, ref int i)
        {
            bool ok = false;
            if (i >= 1 && i + k < n && !char.IsLetter(s[i - 1]) && !char.IsLetter(s[i + k]))
                ok = true;
            if (i >= 1 && i + k >= n && !char.IsLetter(s[i - 1]))
                ok = true;
            if (i < 1 && i + k < n && !char.IsLetter(s[i + k]))
                ok = true;
            if (i < 1 && i + k >= n)
                ok = true;
            if (ok)
                i += k;
        }

        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            string t = "";
            int n = s.Length;

            for (int i = 0; i < n; i++) 
            {
                if (i + 2 < n)
                {
                    string the = s.Substring(i, 3);
                    if (the == "the" || the == "The")
                    {
                        del(ref s, n, 3, ref i);
                    }
                }
                
                if (i + 1 < n)
                {
                    string an = s.Substring(i, 2);
                    if (an == "an" || an == "An")
                    {
                        del(ref s, n, 2, ref i);
                    }
                }

                if (i < n)
                {
                    string a = s.Substring(i, 1);
                    if (a == "a" || a == "A")
                    {
                        del(ref s, n, 1, ref i);
                    }
                }

                if (i < n)
                    t += s[i];
            }

            t = Regex.Replace(t, "Ci", "Si");
            t = Regex.Replace(t, "ci", "si");

            t = Regex.Replace(t, "Ce", "Se");
            t = Regex.Replace(t, "ce", "se");

            t = Regex.Replace(t, ("C|Ck"), "K");
            t = Regex.Replace(t, ("c|ck"), "k");

            t = Regex.Replace(t, "Ee", "I");
            t = Regex.Replace(t, "ee", "i");

            t = Regex.Replace(t, "Oo", "U");
            t = Regex.Replace(t, "oo", "u");
               
            t = Regex.Replace(t, @"([a-zA-Z])e\b", "$1");
            t = Regex.Replace(t, "  ", " ");

            for (int i = 0; i < 200; i++)
                t = Regex.Replace(t, ("([a-zA-Z])\\1"), "$1", RegexOptions.IgnoreCase);
            Console.WriteLine(t);
        }
    }
}
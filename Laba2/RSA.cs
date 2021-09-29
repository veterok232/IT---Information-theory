using System;
using System.Collections.Generic;
using System.Text;
using System.Numerics;

namespace laba2
{
    public class RSA
    {
        const int _PRIMES_NUM = 1000;
        public static List<string> Encode(string message, BigInteger e, BigInteger n)
        {
            List<string> result = new List<string>();

            int symbol_code;
            BigInteger bi;
            var bn = n;

            for (int i = 0; i < message.Length; i++)
            {
                symbol_code = Convert.ToInt32(message[i]);
                bi = new BigInteger(symbol_code);
                
                bi = fast_pow(bi, e, bn);

                result.Add(bi.ToString());
            }

            return result;
        }

        public static string fast_p()
        {
            var bi = new BigInteger(0);
            bi = fast_pow(5, 3, 10);
            return bi.ToString();
        }

        public static string Decode(List<string> message, BigInteger d, BigInteger n)
        {
            string result = "";

            BigInteger bi;
            var bn = n;

            foreach (string item in message)
            {
                bi = BigInteger.Parse(item);
                bi = fast_pow(bi, d, bn);

                int index = Convert.ToInt32(bi.ToString());

                result += Convert.ToChar(index);
            }

            return result;
        }

        public static bool IsSimple(long n)
        {
            if (n < 2)
                return false;

            if (n == 2)
                return true;

            for (long i = 2; i < n / 2 + 1; i++)
                if (n % i == 0)
                    return false;

            return true;
        }

        public static BigInteger calc_e(BigInteger m)
        {
            Random rnd = new Random();
            int upper_bound = m.ToString().Length - 2;
            if (upper_bound < 1) upper_bound = 1;

            BigInteger[] e_list = new BigInteger[_PRIMES_NUM];

            BigInteger e = m - 1;
            int n = 0;

            while ((e >= 3) && (n < _PRIMES_NUM))
            {
                if (BigInteger.GreatestCommonDivisor(e, m) == 1)
                {
                    e_list[n] = e;
                    n++;
                }

                int rand_val = rnd.Next(1, upper_bound);
                e -= (BigInteger.Pow(10, rand_val)) + 1;
            }

           
            int index = rnd.Next(0, n);

            return e_list[index];
        }

        public static BigInteger calc_d(BigInteger e, BigInteger euler_func)
        {
            BigInteger d = gcdex(euler_func, e);
            return d;
        }

        private static BigInteger fast_pow(BigInteger x, BigInteger n, BigInteger bn)
        {
            var result = new BigInteger(1);
            while (n > 0)
            {
                if ((n & 1) == 0)
                {
                    x *= x;
                    x %= bn;
                    n >>= 1;
                }
                else
                {
                    result *= x;
                    result %= bn;
                    --n;
                }
            }

            return result;
        }

        private static BigInteger gcdex(BigInteger a, BigInteger b)
        {
            BigInteger d0 = a, d1 = b;
            BigInteger x0 = 1, x1 = 0;
            BigInteger y0 = 0, y1 = 1;

            while (d1 > 1)
            {
                BigInteger q = d0 / d1;
                BigInteger d2 = d0 % d1;
                BigInteger x2 = x0 - q * x1;
                BigInteger y2 = y0 - q * y1;

                d0 = d1; d1 = d2;
                x0 = x1; x1 = x2;
                y0 = y1; y1 = y2;
            }

            if (y1 < 0) y1 += a;

            return y1;
        }
    }
}

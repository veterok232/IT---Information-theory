using System;
using System.Numerics;
using System.Collections.Generic;

namespace Laba3
{
    class Program
    {
        // Количество бит в числах p и q
        private static int p_size = 256;
        private static int q_size = 80;

        // Быстрое возведение в степень по модулю
        public static BigInteger fast_pow(BigInteger a, BigInteger r, BigInteger n)
        {
            BigInteger a1 = a;
            BigInteger z1 = r;
            BigInteger x = 1;
            while (z1 != 0) {
                while (z1 % 2 == 0) {
                    z1 /= 2;
                    a1 = (a1 * a1) % n;
                }
                z1 -= 1;
                x = (x * a1) % n;
            }
            return x;
        }

        // Расширенный алгоритм Евклида
        private static BigInteger gcdex(BigInteger a, BigInteger b)
        {
            BigInteger d0 = a, d1 = b;
            BigInteger x0 = 1, x1 = 0;
            BigInteger y0 = 0, y1 = 1;
            while (d1 > 1) {
                BigInteger q = d0 / d1;
                BigInteger d2 = d0 % d1;
                BigInteger x2 = x0 - q * x1;
                BigInteger y2 = y0 - q * y1;

                d0 = d1; d1 = d2;
                x0 = x1; x1 = x2;
                y0 = y1; y1 = y2;
            }

            if (y1 < 0) {
                y1 += a;
            }

            return y1;
        }

        // Генерация ключа
        public static BigInteger[] getKey()
        {
            var res = new BigInteger[5];
            Random rand = new Random();

            // Вычисление q и p
            BigInteger q = BigInteger.genPseudoPrime(q_size, 5, rand);
            BigInteger t = 1 << (p_size - q_size);
            BigInteger p = q * t + 1;
            while (!p.isProbablePrime(5)) {
                q = BigInteger.genPseudoPrime(q_size, 5, rand);
                p = q * t + 1;
            }
            res[0] = p;
            res[1] = q;

            // Вычисление g
            BigInteger h = new BigInteger();
            while (true) {
                h.genRandomBits(res[0].bitCount() - 1, rand);
                res[2] = fast_pow(h, (res[0] - 1) / res[1], res[0]);
                if (res[2] >= 1) break;
            }

            // Вычисление y и x
            BigInteger x = new BigInteger();
            x.genRandomBits(res[1].bitCount() - 1, rand);
            res[3] = x;
            res[4] = fast_pow(res[2], x, res[0]);

            return res;
        }

        // Генерация ЭЦП
        public static BigInteger[] getEDS(string message, BigInteger[] key)
        {
            var res = new BigInteger[2];
            Random rand = new Random();

            // Вычисление r
            BigInteger k = new BigInteger();
            k.genRandomBits(key[1].bitCount() - 1, rand);
            res[0] = fast_pow(key[2], k, key[0]) % key[1];

            // Вычисление s
            BigInteger k_reverse = gcdex(key[1], k);
            BigInteger hash = SHA256.GET_SHA256(message);
            res[1] = (k_reverse * (hash + key[3] * res[0])) % key[1];
            
            return res;
        }

        // проверка ЭЦП
        public static BigInteger checkEDS(string message, BigInteger[] eds, BigInteger[] key)
        {
            Random rand = new Random();

            // Вычисление w
            BigInteger s_reverse = gcdex(key[1], eds[1]);
            BigInteger w = s_reverse % key[1];

            // Вычисление u1
            BigInteger hash = SHA256.GET_SHA256(message);
            BigInteger u1 = (hash * w) % key[1];

            // Вычисление u2
            BigInteger u2 = (eds[0] * w) % key[1];

            // Вычисление v
            BigInteger v = ((fast_pow(key[2], u1, key[0]) * fast_pow(key[4], u2, key[0])) % key[0]) % key[1];

            return v;
        }

        // Главная функция
        static void Main(string[] args)
        {
            //-----------------------------------------------------------------------------------------------

            Console.WriteLine("Keys generation..");

            BigInteger[] key = getKey();
            Console.WriteLine("Generation p : {0}", key[0]);
            Console.WriteLine("Generation q : {0}", key[1]);
            Console.WriteLine("Generation g : {0}", key[2]);
            Console.WriteLine("Generation x : {0}", key[3]);
            Console.WriteLine("Generation y : {0}", key[4]);

            Console.WriteLine();

            //-----------------------------------------------------------------------------------------------

            Console.WriteLine("\nGeneration EDS..");

            Console.Write("Enter message: ");
            string message = Console.ReadLine();
            BigInteger[] eds = getEDS(message, key);
            Console.WriteLine("Generation r : {0}", eds[0]);
            Console.WriteLine("Generation s : {0}", eds[1]);

            Console.WriteLine();

            //-----------------------------------------------------------------------------------------------

            Console.WriteLine("\nEDS check..");
            Console.Write("Enter message: ");
            message = Console.ReadLine();

            BigInteger check = checkEDS(message, eds, key);
            Console.WriteLine("Generation v : {0} ", check);
            string check_res = "";
            if (check != eds[0]) {
                check_res = "EDS incorrect";
            }
            else {
                check_res = "EDS correct";
            }
            Console.WriteLine("Check result : {0} ", check_res);
            
            Console.WriteLine();

            //-----------------------------------------------------------------------------------------------

            Console.Write("\nPress Enter to exit...");
            Console.ReadLine();

            //-----------------------------------------------------------------------------------------------
        }
    }
}

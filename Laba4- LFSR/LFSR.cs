using System;
using System.IO;
using System.Windows;

namespace laba4
{
    class LFSR
    {
        private const int BUFFER_SIZE = 1024;       //Размер буфера для чтения
        private const int BITS_NUM = 8;             //Количество бит в слове
        public static ulong register;               //Регистр сдвига

        //Метод шифрования/дешифрования
        public static void Crypt(string srcPath, string destPath)
        {
            BinaryReader reader = new BinaryReader(File.Open(srcPath, FileMode.Open));
            BinaryWriter writer = new BinaryWriter(File.Open(destPath, FileMode.Create));

            byte[] buffer = new byte[BUFFER_SIZE];
            int readBytes;

            try
            {
                do
                {   
                    //Читаем баты из файла в буфер
                    readBytes = reader.Read(buffer, 0, BUFFER_SIZE);

                    for (int i = 0; i < BUFFER_SIZE; i++)
                    {
                        for (int j = 0; j < BITS_NUM; j++)
                        {
                            buffer[i] = (byte)(buffer[i] ^ (BitKey() << (8 - j)));
                        }
                    }

                    writer.Write(buffer, 0, readBytes);
                } while (readBytes > 0); //Пока есть что читать
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            finally
            {
                reader.Close();
                writer.Close();
            }
        }

        // Многочлен обратной связи: x^30 + x^16 + x^15 + x + 1
        public static ulong BitKey()
        {
            register = (((
                (register >> 0) ^
                (register >> 1) ^
                (register >> 15) ^
                (register >> 16) & 0x1) << 29) | (register >> 1);
            return register & 0x1;
        }
    }
}

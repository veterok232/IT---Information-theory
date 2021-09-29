using Microsoft.Win32;
using System;
using System.Text;
using System.Windows;

namespace laba4
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public static string srcPath;
        public static string dstPath;

        public MainWindow()
        {
            InitializeComponent();
        }

        private void cipher_Click(object sender, RoutedEventArgs e)
        {
            if (DataIsCorrect())
            {
                ulong inputKey = Convert.ToUInt64(key.Text);
                LFSR.register = inputKey;

                LFSR.Crypt(srcPath, dstPath);
                MessageBox.Show("The file was successfully encrypted/decrypted!");
            }
        }

        private void btnSrc_Click(object sender, RoutedEventArgs e)
        {
            string path = "";
            OpenFileDialog openFileDialog = new OpenFileDialog();
            if (openFileDialog.ShowDialog() == true)
            {
                path = openFileDialog.FileName;
            }
            srcPath = path;
            src.Text = srcPath;
        }

        private void btnDest_Click(object sender, RoutedEventArgs e)
        {
            string path = "";
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            if (saveFileDialog.ShowDialog() == true)
            {
                path = saveFileDialog.FileName;
            }

            dstPath = path;
            dest.Text = dstPath;
        }
        private bool DataIsCorrect()
        {
            try
            {
                ulong data = Convert.ToUInt64(key.Text);
                return true;
            }
            catch
            {
                MessageBox.Show("Error! Incorrect data!");
                return false;
            }
        }
    }
}

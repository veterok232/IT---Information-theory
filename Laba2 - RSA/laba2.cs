using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Numerics;


namespace laba2
{
    public partial class frmMain : Form
    {
        public frmMain()
        {
            InitializeComponent();
            
        }

        private void btnEncrypt_Click(object sender, EventArgs e)
        {
            if ((textFieldEncrypt_p.Text.Length > 0) && (textFieldEncrypt_q.Text.Length > 0))
            {
                BigInteger p = BigInteger.Parse(textFieldEncrypt_p.Text);
                BigInteger q = BigInteger.Parse(textFieldEncrypt_q.Text);

                string message = textFieldSource.Text;
                message.Trim();

                BigInteger n = p * q;
                BigInteger euler_func = (p - 1) * (q - 1);
                BigInteger _e;

                if (textFieldEncrypt_e.Text.Length == 0)
                {
                    _e = RSA.calc_e(euler_func);
                }
                else
                {
                    _e = Convert.ToInt64(textFieldEncrypt_e.Text);
                }

                MessageBox.Show("e = " + _e.ToString());

                textFieldEncrypt_e.Text = _e.ToString();

                BigInteger d = RSA.calc_d(_e, euler_func);
                MessageBox.Show("d = " + d.ToString());

                List<string> result_message = RSA.Encode(message, _e, n);

                textFieldDecrypt_d.Text = d.ToString();
                textFieldDecrypt_n.Text = n.ToString();

                textFieldResult.Text = "";

                foreach (string item in result_message)
                {
                    textFieldResult.Text += item + " ";
                }

                textFieldResult.Text = textFieldResult.Text.Trim();
            }
            else
                MessageBox.Show("Введите p и q!");
        }

        private void btnDecrypt_Click(object sender, EventArgs e)
        {
            if ((textFieldDecrypt_d.Text.Length > 0) && (textFieldDecrypt_n.Text.Length > 0))
            {
                BigInteger d = BigInteger.Parse(textFieldDecrypt_d.Text);
                BigInteger n = BigInteger.Parse(textFieldDecrypt_n.Text);

                string[] symbols = textFieldSource.Text.Split(' ');
                List<string> message = new List<string>();

                foreach (string symb in symbols)
                {
                    message.Add(symb);
                }

                string result_message = RSA.Decode(message, d, n);

                textFieldResult.Text = result_message;
            }
            else
                MessageBox.Show("Введите секретный ключ!");
        }
    }
}

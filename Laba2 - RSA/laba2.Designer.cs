
namespace laba2
{
    partial class frmMain
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.textFieldSource = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.textFieldResult = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.textFieldEncrypt_q = new System.Windows.Forms.TextBox();
            this.groupBoxEncryption = new System.Windows.Forms.GroupBox();
            this.textFieldEncrypt_e = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.textFieldEncrypt_p = new System.Windows.Forms.TextBox();
            this.btnEncrypt = new System.Windows.Forms.Button();
            this.groupBoxDecryption = new System.Windows.Forms.GroupBox();
            this.textFieldDecrypt_d = new System.Windows.Forms.TextBox();
            this.btnDecrypt = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.textFieldDecrypt_n = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.btnResetFocus = new System.Windows.Forms.Button();
            this.groupBoxEncryption.SuspendLayout();
            this.groupBoxDecryption.SuspendLayout();
            this.SuspendLayout();
            // 
            // textFieldSource
            // 
            this.textFieldSource.Font = new System.Drawing.Font("Times New Roman", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.textFieldSource.Location = new System.Drawing.Point(12, 39);
            this.textFieldSource.Multiline = true;
            this.textFieldSource.Name = "textFieldSource";
            this.textFieldSource.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textFieldSource.Size = new System.Drawing.Size(1158, 193);
            this.textFieldSource.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Roboto Lt", 12F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point);
            this.label1.Location = new System.Drawing.Point(12, 12);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(209, 24);
            this.label1.TabIndex = 1;
            this.label1.Text = "Исходное сообщение:";
            // 
            // textFieldResult
            // 
            this.textFieldResult.Font = new System.Drawing.Font("Times New Roman", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.textFieldResult.Location = new System.Drawing.Point(12, 289);
            this.textFieldResult.Multiline = true;
            this.textFieldResult.Name = "textFieldResult";
            this.textFieldResult.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textFieldResult.Size = new System.Drawing.Size(1158, 193);
            this.textFieldResult.TabIndex = 2;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Roboto Lt", 12F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point);
            this.label2.Location = new System.Drawing.Point(12, 262);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(212, 24);
            this.label2.TabIndex = 3;
            this.label2.Text = "Выходное сообщение:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Roboto Lt", 12F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point);
            this.label4.Location = new System.Drawing.Point(14, 32);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(25, 24);
            this.label4.TabIndex = 6;
            this.label4.Text = "p:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Roboto Lt", 12F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point);
            this.label5.Location = new System.Drawing.Point(307, 29);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(25, 24);
            this.label5.TabIndex = 8;
            this.label5.Text = "q:";
            // 
            // textFieldEncrypt_q
            // 
            this.textFieldEncrypt_q.Location = new System.Drawing.Point(338, 29);
            this.textFieldEncrypt_q.Name = "textFieldEncrypt_q";
            this.textFieldEncrypt_q.ScrollBars = System.Windows.Forms.ScrollBars.Horizontal;
            this.textFieldEncrypt_q.Size = new System.Drawing.Size(235, 29);
            this.textFieldEncrypt_q.TabIndex = 7;
            // 
            // groupBoxEncryption
            // 
            this.groupBoxEncryption.Controls.Add(this.textFieldEncrypt_e);
            this.groupBoxEncryption.Controls.Add(this.label7);
            this.groupBoxEncryption.Controls.Add(this.textFieldEncrypt_p);
            this.groupBoxEncryption.Controls.Add(this.btnEncrypt);
            this.groupBoxEncryption.Controls.Add(this.label5);
            this.groupBoxEncryption.Controls.Add(this.textFieldEncrypt_q);
            this.groupBoxEncryption.Controls.Add(this.label4);
            this.groupBoxEncryption.Font = new System.Drawing.Font("Roboto Lt", 10.8F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point);
            this.groupBoxEncryption.Location = new System.Drawing.Point(12, 516);
            this.groupBoxEncryption.Name = "groupBoxEncryption";
            this.groupBoxEncryption.Size = new System.Drawing.Size(592, 181);
            this.groupBoxEncryption.TabIndex = 11;
            this.groupBoxEncryption.TabStop = false;
            this.groupBoxEncryption.Text = "Шифрование";
            // 
            // textFieldEncrypt_e
            // 
            this.textFieldEncrypt_e.Location = new System.Drawing.Point(45, 64);
            this.textFieldEncrypt_e.Name = "textFieldEncrypt_e";
            this.textFieldEncrypt_e.ScrollBars = System.Windows.Forms.ScrollBars.Horizontal;
            this.textFieldEncrypt_e.Size = new System.Drawing.Size(528, 29);
            this.textFieldEncrypt_e.TabIndex = 12;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Roboto Lt", 12F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point);
            this.label7.Location = new System.Drawing.Point(14, 67);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(24, 24);
            this.label7.TabIndex = 11;
            this.label7.Text = "e:";
            // 
            // textFieldEncrypt_p
            // 
            this.textFieldEncrypt_p.Location = new System.Drawing.Point(45, 29);
            this.textFieldEncrypt_p.Name = "textFieldEncrypt_p";
            this.textFieldEncrypt_p.ScrollBars = System.Windows.Forms.ScrollBars.Horizontal;
            this.textFieldEncrypt_p.Size = new System.Drawing.Size(245, 29);
            this.textFieldEncrypt_p.TabIndex = 10;
            // 
            // btnEncrypt
            // 
            this.btnEncrypt.Font = new System.Drawing.Font("Roboto", 10.8F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point);
            this.btnEncrypt.Location = new System.Drawing.Point(14, 120);
            this.btnEncrypt.Name = "btnEncrypt";
            this.btnEncrypt.Size = new System.Drawing.Size(559, 40);
            this.btnEncrypt.TabIndex = 9;
            this.btnEncrypt.Text = "Шифровать";
            this.btnEncrypt.UseVisualStyleBackColor = true;
            this.btnEncrypt.Click += new System.EventHandler(this.btnEncrypt_Click);
            // 
            // groupBoxDecryption
            // 
            this.groupBoxDecryption.Controls.Add(this.textFieldDecrypt_d);
            this.groupBoxDecryption.Controls.Add(this.btnDecrypt);
            this.groupBoxDecryption.Controls.Add(this.label3);
            this.groupBoxDecryption.Controls.Add(this.textFieldDecrypt_n);
            this.groupBoxDecryption.Controls.Add(this.label6);
            this.groupBoxDecryption.Font = new System.Drawing.Font("Roboto Lt", 10.8F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point);
            this.groupBoxDecryption.Location = new System.Drawing.Point(621, 516);
            this.groupBoxDecryption.Name = "groupBoxDecryption";
            this.groupBoxDecryption.Size = new System.Drawing.Size(549, 181);
            this.groupBoxDecryption.TabIndex = 12;
            this.groupBoxDecryption.TabStop = false;
            this.groupBoxDecryption.Text = "Дешифрование";
            // 
            // textFieldDecrypt_d
            // 
            this.textFieldDecrypt_d.Location = new System.Drawing.Point(45, 64);
            this.textFieldDecrypt_d.Name = "textFieldDecrypt_d";
            this.textFieldDecrypt_d.ScrollBars = System.Windows.Forms.ScrollBars.Horizontal;
            this.textFieldDecrypt_d.Size = new System.Drawing.Size(482, 29);
            this.textFieldDecrypt_d.TabIndex = 10;
            // 
            // btnDecrypt
            // 
            this.btnDecrypt.Font = new System.Drawing.Font("Roboto", 10.8F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point);
            this.btnDecrypt.Location = new System.Drawing.Point(14, 120);
            this.btnDecrypt.Name = "btnDecrypt";
            this.btnDecrypt.Size = new System.Drawing.Size(513, 40);
            this.btnDecrypt.TabIndex = 9;
            this.btnDecrypt.Text = "Дешифровать";
            this.btnDecrypt.UseVisualStyleBackColor = true;
            this.btnDecrypt.Click += new System.EventHandler(this.btnDecrypt_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Roboto Lt", 12F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point);
            this.label3.Location = new System.Drawing.Point(14, 29);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(25, 24);
            this.label3.TabIndex = 8;
            this.label3.Text = "n:";
            // 
            // textFieldDecrypt_n
            // 
            this.textFieldDecrypt_n.Location = new System.Drawing.Point(45, 29);
            this.textFieldDecrypt_n.Name = "textFieldDecrypt_n";
            this.textFieldDecrypt_n.ScrollBars = System.Windows.Forms.ScrollBars.Horizontal;
            this.textFieldDecrypt_n.Size = new System.Drawing.Size(482, 29);
            this.textFieldDecrypt_n.TabIndex = 7;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Roboto Lt", 12F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point);
            this.label6.Location = new System.Drawing.Point(14, 67);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(25, 24);
            this.label6.TabIndex = 6;
            this.label6.Text = "d:";
            // 
            // btnResetFocus
            // 
            this.btnResetFocus.Location = new System.Drawing.Point(0, 0);
            this.btnResetFocus.Name = "btnResetFocus";
            this.btnResetFocus.Size = new System.Drawing.Size(0, 0);
            this.btnResetFocus.TabIndex = 13;
            this.btnResetFocus.UseVisualStyleBackColor = true;
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1182, 753);
            this.Controls.Add(this.btnResetFocus);
            this.Controls.Add(this.groupBoxDecryption);
            this.Controls.Add(this.groupBoxEncryption);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.textFieldResult);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textFieldSource);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "frmMain";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Laba 2 - RSA";
            this.groupBoxEncryption.ResumeLayout(false);
            this.groupBoxEncryption.PerformLayout();
            this.groupBoxDecryption.ResumeLayout(false);
            this.groupBoxDecryption.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textFieldSource;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textFieldResult;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox textFieldEncrypt_q;
        private System.Windows.Forms.GroupBox groupBoxEncryption;
        private System.Windows.Forms.TextBox textFieldEncrypt_p;
        private System.Windows.Forms.Button btnEncrypt;
        private System.Windows.Forms.GroupBox groupBoxDecryption;
        private System.Windows.Forms.TextBox textFieldDecrypt_d;
        private System.Windows.Forms.Button btnDecrypt;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textFieldDecrypt_n;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button btnResetFocus;
        private System.Windows.Forms.TextBox textFieldEncrypt_e;
        private System.Windows.Forms.Label label7;
    }
}


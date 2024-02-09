namespace Thermometer_Monitoring
{
    partial class Form1
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            label1 = new Label();
            tb_studentid = new TextBox();
            tb_name = new TextBox();
            tb_time = new TextBox();
            tb_body = new TextBox();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            label5 = new Label();
            button1 = new Button();
            label6 = new Label();
            tb_Fall = new TextBox();
            label7 = new Label();
            label8 = new Label();
            pictureBox1 = new PictureBox();
            label9 = new Label();
            chart1 = new System.Windows.Forms.DataVisualization.Charting.Chart();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            ((System.ComponentModel.ISupportInitialize)chart1).BeginInit();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 18F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label1.Location = new Point(12, 9);
            label1.Name = "label1";
            label1.Size = new Size(440, 32);
            label1.TabIndex = 0;
            label1.Text = "iCare Elderly Care Monitoring System";
            label1.Click += label1_Click;
            // 
            // tb_studentid
            // 
            tb_studentid.Location = new Point(187, 55);
            tb_studentid.Name = "tb_studentid";
            tb_studentid.Size = new Size(213, 23);
            tb_studentid.TabIndex = 1;
            // 
            // tb_name
            // 
            tb_name.Location = new Point(187, 98);
            tb_name.Name = "tb_name";
            tb_name.ReadOnly = true;
            tb_name.Size = new Size(213, 23);
            tb_name.TabIndex = 2;
            tb_name.TextChanged += tb_name_TextChanged;
            // 
            // tb_time
            // 
            tb_time.Location = new Point(187, 146);
            tb_time.Name = "tb_time";
            tb_time.ReadOnly = true;
            tb_time.Size = new Size(213, 23);
            tb_time.TabIndex = 3;
            tb_time.TextChanged += tb_time_TextChanged;
            // 
            // tb_body
            // 
            tb_body.Location = new Point(187, 195);
            tb_body.Name = "tb_body";
            tb_body.ReadOnly = true;
            tb_body.Size = new Size(213, 23);
            tb_body.TabIndex = 4;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(64, 106);
            label2.Name = "label2";
            label2.Size = new Size(39, 15);
            label2.TabIndex = 5;
            label2.Text = "Name";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(73, 59);
            label3.Name = "label3";
            label3.Size = new Size(18, 15);
            label3.TabIndex = 6;
            label3.Text = "ID";
            label3.Click += label3_Click;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(50, 146);
            label4.Name = "label4";
            label4.Size = new Size(66, 15);
            label4.TabIndex = 7;
            label4.Text = "Time Taken";
            label4.Click += label4_Click;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(36, 197);
            label5.Name = "label5";
            label5.Size = new Size(103, 15);
            label5.TabIndex = 8;
            label5.Text = "Body Temperature";
            label5.Click += label5_Click;
            // 
            // button1
            // 
            button1.Location = new Point(415, 55);
            button1.Name = "button1";
            button1.Size = new Size(75, 23);
            button1.TabIndex = 9;
            button1.Text = "Fetch!";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(27, 252);
            label6.Name = "label6";
            label6.Size = new Size(111, 15);
            label6.TabIndex = 10;
            label6.Text = "Assistance Needed?";
            label6.Click += label6_Click;
            // 
            // tb_Fall
            // 
            tb_Fall.Location = new Point(187, 252);
            tb_Fall.Name = "tb_Fall";
            tb_Fall.ReadOnly = true;
            tb_Fall.Size = new Size(213, 23);
            tb_Fall.TabIndex = 11;
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Font = new Font("Segoe UI", 9F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label7.Location = new Point(534, 58);
            label7.Name = "label7";
            label7.Size = new Size(180, 15);
            label7.TabIndex = 12;
            label7.Text = "Auto Refresh every 10 seconds";
            label7.Click += label7_Click;
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Font = new Font("Segoe UI", 9F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label8.Location = new Point(12, 296);
            label8.Name = "label8";
            label8.Size = new Size(152, 30);
            label8.TabIndex = 13;
            label8.Text = "See a RED popup?\r\nThat person needs HELP!!!";
            label8.TextAlign = ContentAlignment.TopCenter;
            label8.Click += label8_Click;
            // 
            // pictureBox1
            // 
            pictureBox1.Image = (Image)resources.GetObject("pictureBox1.Image");
            pictureBox1.Location = new Point(534, 125);
            pictureBox1.Margin = new Padding(3, 2, 3, 2);
            pictureBox1.Name = "pictureBox1";
            pictureBox1.Size = new Size(199, 190);
            pictureBox1.TabIndex = 14;
            pictureBox1.TabStop = false;
            pictureBox1.Click += pictureBox1_Click;
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.BackColor = Color.Red;
            label9.Font = new Font("Segoe UI", 20F, FontStyle.Bold);
            label9.Location = new Point(494, 17);
            label9.Name = "label9";
            label9.Size = new Size(342, 37);
            label9.TabIndex = 15;
            label9.Text = "ERROR, CAN'T CONNECT!";
            label9.Click += label9_Click;
            // 
            // chart1
            // 
            chartArea1.Name = "ChartArea1";
            chart1.ChartAreas.Add(chartArea1);
            legend1.Name = "Legend1";
            chart1.Legends.Add(legend1);
            chart1.Location = new Point(50, 367);
            chart1.Name = "chart1";
            chart1.Size = new Size(744, 300);
            chart1.TabIndex = 16;
            chart1.Text = "chart1";
            chart1.Click += chart1_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(913, 755);
            Controls.Add(chart1);
            Controls.Add(label9);
            Controls.Add(pictureBox1);
            Controls.Add(label8);
            Controls.Add(label7);
            Controls.Add(tb_Fall);
            Controls.Add(label6);
            Controls.Add(button1);
            Controls.Add(label5);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(tb_body);
            Controls.Add(tb_time);
            Controls.Add(tb_name);
            Controls.Add(tb_studentid);
            Controls.Add(label1);
            Name = "Form1";
            Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
            ((System.ComponentModel.ISupportInitialize)chart1).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private TextBox tb_studentid;
        private TextBox tb_name;
        private TextBox tb_time;
        private TextBox tb_body;
        private Label label2;
        private Label label3;
        private Label label4;
        private Label label5;
        private Button button1;
        private Label label6;
        private TextBox tb_Fall;
        private Label label7;
        private Label label8;
        private PictureBox pictureBox1;
        private Label label9;
        private System.Windows.Forms.DataVisualization.Charting.Chart chart1;
    }
}

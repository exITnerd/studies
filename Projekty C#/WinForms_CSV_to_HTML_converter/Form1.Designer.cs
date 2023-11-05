namespace WinFormsCSVtoHTML_Converter
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
            btnReadFile = new Button();
            label1 = new Label();
            btnSaveFile = new Button();
            btnConvert = new Button();
            tableLayoutPanel1 = new TableLayoutPanel();
            lbl_folder_path = new Label();
            lbl_file_path = new Label();
            lbl_status = new Label();
            openFileDialog1 = new OpenFileDialog();
            saveFileDialog1 = new SaveFileDialog();
            tableLayoutPanel1.SuspendLayout();
            SuspendLayout();
            // 
            // btnReadFile
            // 
            btnReadFile.Anchor = AnchorStyles.Left | AnchorStyles.Right;
            btnReadFile.AutoSize = true;
            btnReadFile.Font = new Font("Segoe UI", 24F, FontStyle.Regular, GraphicsUnit.Point);
            btnReadFile.Location = new Point(3, 205);
            btnReadFile.Name = "btnReadFile";
            btnReadFile.Size = new Size(436, 100);
            btnReadFile.TabIndex = 0;
            btnReadFile.Text = "Select CSV file location";
            btnReadFile.UseVisualStyleBackColor = true;
            btnReadFile.Click += btnReadFile_Click;
            // 
            // label1
            // 
            label1.Dock = DockStyle.Top;
            label1.Font = new Font("Segoe UI", 24F, FontStyle.Bold, GraphicsUnit.Point);
            label1.Location = new Point(0, 0);
            label1.Name = "label1";
            label1.Size = new Size(1264, 50);
            label1.TabIndex = 1;
            label1.Text = "CSV to HTML Converter";
            label1.TextAlign = ContentAlignment.TopCenter;
            // 
            // btnSaveFile
            // 
            btnSaveFile.Anchor = AnchorStyles.Left | AnchorStyles.Right;
            btnSaveFile.AutoSize = true;
            btnSaveFile.Font = new Font("Segoe UI", 24F, FontStyle.Regular, GraphicsUnit.Point);
            btnSaveFile.Location = new Point(824, 205);
            btnSaveFile.Name = "btnSaveFile";
            btnSaveFile.Size = new Size(437, 100);
            btnSaveFile.TabIndex = 2;
            btnSaveFile.Text = "Select HTML file destination";
            btnSaveFile.UseVisualStyleBackColor = true;
            btnSaveFile.Click += btnSaveFile_Click;
            // 
            // btnConvert
            // 
            btnConvert.Anchor = AnchorStyles.Left | AnchorStyles.Right;
            btnConvert.AutoSize = true;
            btnConvert.Enabled = false;
            btnConvert.Font = new Font("Segoe UI", 24F, FontStyle.Bold, GraphicsUnit.Point);
            btnConvert.Location = new Point(445, 546);
            btnConvert.Name = "btnConvert";
            btnConvert.Size = new Size(373, 100);
            btnConvert.TabIndex = 3;
            btnConvert.Text = "Convert";
            btnConvert.UseVisualStyleBackColor = true;
            btnConvert.Click += btnConvert_Click;
            // 
            // tableLayoutPanel1
            // 
            tableLayoutPanel1.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            tableLayoutPanel1.ColumnCount = 3;
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 35F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 30F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 35F));
            tableLayoutPanel1.Controls.Add(btnReadFile, 0, 1);
            tableLayoutPanel1.Controls.Add(btnConvert, 1, 3);
            tableLayoutPanel1.Controls.Add(btnSaveFile, 2, 1);
            tableLayoutPanel1.Controls.Add(lbl_folder_path, 2, 2);
            tableLayoutPanel1.Controls.Add(lbl_file_path, 0, 2);
            tableLayoutPanel1.Controls.Add(lbl_status, 1, 2);
            tableLayoutPanel1.Location = new Point(0, 0);
            tableLayoutPanel1.Name = "tableLayoutPanel1";
            tableLayoutPanel1.RowCount = 4;
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.Size = new Size(1264, 682);
            tableLayoutPanel1.TabIndex = 4;
            // 
            // lbl_folder_path
            // 
            lbl_folder_path.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            lbl_folder_path.AutoSize = true;
            lbl_folder_path.Font = new Font("Segoe UI", 15.75F, FontStyle.Italic, GraphicsUnit.Point);
            lbl_folder_path.Location = new Point(824, 340);
            lbl_folder_path.Name = "lbl_folder_path";
            lbl_folder_path.Size = new Size(437, 30);
            lbl_folder_path.TabIndex = 5;
            lbl_folder_path.Text = "Chosen file destination: none";
            lbl_folder_path.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // lbl_file_path
            // 
            lbl_file_path.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            lbl_file_path.AutoSize = true;
            lbl_file_path.Font = new Font("Segoe UI", 15.75F, FontStyle.Italic, GraphicsUnit.Point);
            lbl_file_path.Location = new Point(3, 340);
            lbl_file_path.Name = "lbl_file_path";
            lbl_file_path.Size = new Size(436, 30);
            lbl_file_path.TabIndex = 4;
            lbl_file_path.Text = "Chosen file: none";
            lbl_file_path.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // lbl_status
            // 
            lbl_status.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            lbl_status.AutoSize = true;
            lbl_status.Font = new Font("Segoe UI", 15.75F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point);
            lbl_status.ForeColor = Color.Red;
            lbl_status.Location = new Point(445, 340);
            lbl_status.Name = "lbl_status";
            lbl_status.Size = new Size(373, 170);
            lbl_status.TabIndex = 6;
            lbl_status.Text = "Choose CSV file location and HTML file destination before converting!";
            lbl_status.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // openFileDialog1
            // 
            openFileDialog1.FileName = "openFileDialog1";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1264, 681);
            Controls.Add(label1);
            Controls.Add(tableLayoutPanel1);
            Name = "Form1";
            Text = "CSV to HTML Converter";
            tableLayoutPanel1.ResumeLayout(false);
            tableLayoutPanel1.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private Button btnReadFile;
        private Label label1;
        private Button btnSaveFile;
        private Button btnConvert;
        private TableLayoutPanel tableLayoutPanel1;
        private Label lbl_file_path;
        private Label lbl_folder_path;
        private Label lbl_status;
        private OpenFileDialog openFileDialog1;
        private SaveFileDialog saveFileDialog1;
    }
}
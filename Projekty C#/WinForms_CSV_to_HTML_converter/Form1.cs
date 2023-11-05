using Microsoft.VisualBasic.Logging;
using System.Collections.Specialized;
using System.Text;
using System.Windows.Forms;

namespace WinFormsCSVtoHTML_Converter
{
    public partial class Form1 : Form
    {
        bool folderLocation = false;
        bool fileLocation = false;
        string inputPath = "";
        string outputPath = "";
        public Form1()
        {
            InitializeComponent();
        }

        private void btnReadFile_Click(object sender, EventArgs e)
        {
            OpenFileDialog openfiledialog = new OpenFileDialog();
            openfiledialog.Filter = "CSV files (*.csv)|*.csv|All files (*.*)|*.*";
            if (openfiledialog.ShowDialog() == DialogResult.OK)
            {
                string selectedFilePath = openfiledialog.FileName;
                if (System.IO.Path.GetExtension(selectedFilePath) == ".csv")
                {
                    lbl_status.Text = "Choose HTML file destination before converting!";
                    lbl_file_path.Text = "Chosen file location: " + selectedFilePath;
                    inputPath = selectedFilePath;
                    fileLocation = true;
                    if (folderLocation && fileLocation)
                    {
                        lbl_status.Text = "Ready to convert!";
                        btnConvert.Enabled = true;
                    }
                    else
                    {
                        btnConvert.Enabled = false;
                    }
                }
                else
                {
                    MessageBox.Show("Please select a .csv file.", "Invalid File Type", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                }
            }
        }

        private void btnSaveFile_Click(object sender, EventArgs e)
        {
            SaveFileDialog savefiledialog = new SaveFileDialog();
            savefiledialog.Filter = "HTML files (*.html)|*.html|All files (*.*)|*.*";
            if (savefiledialog.ShowDialog() == DialogResult.OK)
            {
                lbl_status.Text = "Choose CSV file location before converting!";
                lbl_folder_path.Text = "Chosen file destination: " + savefiledialog.FileName;
                outputPath = savefiledialog.FileName;
                folderLocation = true;
                if (folderLocation && fileLocation)
                {
                    lbl_status.Text = "Ready to convert!";
                    btnConvert.Enabled = true;
                }
                else
                {
                    btnConvert.Enabled = false;
                }
            }
        }

        private void btnConvert_Click(object sender, EventArgs e)
        {
            try
            {
                string[] csvData = ReadCsvFile(inputPath);
                string htmlTable = ConvertCsvToHtmlTable(csvData);
                SaveHtmlToFile(htmlTable, outputPath);
                lbl_status.ForeColor = Color.Green;
                lbl_status.Text = "Successfully converted!";
            }
            catch (IOException exception)
            {
                lbl_status.Text = "An error occurred while processing the file: " + exception.Message;
            }
        }

        static string[] ReadCsvFile(string filePath)
        {
            using (var sr = new StreamReader(filePath))
            {
                var lines = new List<string>();
                string line;
                while ((line = sr.ReadLine()) != null)
                {
                    lines.Add(line);
                }
                return lines.ToArray();
            }
        }

        static string ConvertCsvToHtmlTable(string[] csvData)
        {
            var table = new StringBuilder("<table>");
            bool isFirstRow = true;

            foreach (var csvLine in csvData)
            {
                table.Append("<tr>");
                string[] words = csvLine.Split(',');

                foreach (var word in words)
                {
                    if (isFirstRow)
                    {
                        table.AppendFormat("<th>{0}</th>", word);
                    }
                    else
                    {
                        table.AppendFormat("<td>{0}</td>", word);
                    }
                }
                isFirstRow = false;
                table.Append("</tr>");
            }
            table.Append("</table>");

            // Add table style
            table.Append(@"<style>
            table {
                font-family: arial, sans-serif;
                border-collapse: collapse;
                width: 100%;
            }
            td, th {
                border: 1px solid #dddddd;
                text-align: left;
                padding: 8px;
            }
            tr:nth-child(even) {
                background-color: #dddddd;
            }
            </style>");

            return table.ToString();
        }

        static void SaveHtmlToFile(string htmlContent, string filePath)
        {
            File.WriteAllText(filePath, htmlContent);
        }
    }
}
using System;
using System.IO;
using System.Text;

class Program
{
    static void Main(string[] args)
    {
        if (args.Length != 2)
        {
            Console.WriteLine("Usage: CsvToHtmlConverter <inputFileNameWithoutExtension> <outputFileNameWithoutExtension>");
            return;
        }

        string inputFileName = args[0] + ".csv";
        string outputFileName = args[1] + ".html";

        string inputPath = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.Desktop), inputFileName);
        string outputPath = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.Desktop), outputFileName);

        try
        {
            string[] csvData = ReadCsvFile(inputPath);
            string htmlTable = ConvertCsvToHtmlTable(csvData);
            SaveHtmlToFile(htmlTable, outputPath);
            Console.WriteLine("Success!");
            Console.WriteLine("Data has been saved to " + outputFileName);
        }
        catch (IOException e)
        {
            Console.WriteLine("An error occurred while processing the file:");
            Console.WriteLine(e.Message);
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

// Program.cs
//
// CECS 342 Assignment 2
// File Type Report
// Contributors:
//    Justin Do
//    Anh Le
//    Jonathan Martinez
//    Long Nguyen

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Xml.Linq;

namespace FileTypeReport {
  internal static class Program {
    // 1. Enumerate all files in a folder recursively
    private static IEnumerable<string> EnumerateFilesRecursively(string path) {
      // TODO: Fill in your code here.
    }

    // Human readable byte size
    private static string FormatByteSize(long byteSize) {
      // TODO: Fill in your code here.
    }

    // Create an HTML report file
    private static XDocument CreateReport(IEnumerable<string> files) {
      // 2. Process data
      var query =
        from file in files
        let ext = Path.GetExtension(file).ToLower() // Stores the lowercase extension for each file
        group file by ext into fileGroup            // organize all files into groups
        select new {
          Type = fileGroup.Key == "" ? "[no extension]" : fileGroup.Key, // Checks if extension is empty & labels it
          Count = fileGroup.Count(), //count the amount of that file type in the group
          TotalSize = FormatByteSize(fileGroup.Sum(f => f.Length)) //use formatbytesize to display how much storage the files take up
        };

      // 3. Functionally construct XML
      var alignment = new XAttribute("align", "right");
      var style = "table, th, td { border: 1px solid black; }";

      var tableRows = // TODO: Fill in your code here.
        
      var table = new XElement("table",
        new XElement("thead",
          new XElement("tr",
            new XElement("th", "Type"),
            new XElement("th", "Count"),
            new XElement("th", "Total Size"))),
        new XElement("tbody", tableRows));

      return new XDocument(
        new XDocumentType("html", null, null, null),
          new XElement("html",
            new XElement("head",
              new XElement("title", "File Report"),
              new XElement("style", style)),
            new XElement("body", table)));
    }

    // Console application with two arguments
    public static void Main(string[] args) {
      try {
        string inputFolder = args[0];
        string reportFile  = args[1];
        CreateReport(EnumerateFilesRecursively(inputFolder)).Save(reportFile);
      } catch {
        Console.WriteLine("Usage: FileTypeReport <folder> <report file>");
      }
    }
  }
}

using ikvm.lang;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Display
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Send(object sender, RoutedEventArgs e)
        {
            //char[] Text_To_Send =TextString.Text//.ToCharArray();
            //TextString.Text;
            string fileName = Directory.GetCurrentDirectory() + "\\..\\..\\..\\data.txt";

            // Check if file already exists. If yes, delete it.
            if (File.Exists(fileName))
            {
                File.Delete(fileName);
            }
            //FileStream fs = File.Create(fileName);
            //Byte[] code = new UTF8Encoding(true).GetBytes(TextString.Text);
            //fs.Write(code, 0, code.Length);

            ///or
            StreamWriter sw = File.CreateText(fileName);
            sw.WriteLine(TextString.Text);
            sw.Close();


            //MessageBox.Show(dir);
        }




        /*[StructLayout(LayoutKind.Sequential, Pack =1)]
        struct variables_t
        {
            public string name; 
            public string value;
        }

        //[DllImport(@"/bin/Debug/net6.0-windows/Display.dll", CallingConvention = CallingConvention.Cdecl)]
        [DllImport(@"Display.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern int function(ref variables_t variables);*/
    }
}

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace maturski
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("1");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("2");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("3");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("4");
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            serialPort1.Open();
        }

        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            if (serialPort1.ReadLine() == "D25")
                serialPort1.WriteLine("5");

            if (serialPort1.ReadLine() == "G25")
                serialPort1.WriteLine("6");
        }
    }
}

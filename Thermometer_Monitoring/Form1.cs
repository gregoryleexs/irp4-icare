using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net.Http;
using Microsoft.VisualBasic;
using Newtonsoft.Json;
using Tulpep.NotificationWindow;
using System.Windows.Forms.DataVisualization.Charting;

namespace Thermometer_Monitoring
{
    public partial class Form1 : Form
    {
        public class TCheck
        {
            float recordedtemp { get; set; }
        }

        public class Information
        {
            //Information class same as API format
            public int id { get; set; }
            public DateTime updatetime { get; set; }
            public string name { get; set; }
            public string studentid { get; set; }
            public float body { get; set; }

            //public float humd { get; set; }
            //public float temp { get; set; }
            //public float dist { get; set; }
            public bool fall { get; set; }
        }

        HttpClient client = new HttpClient();

        public Form1()
        {
            InitializeComponent();
            initGraph();
            DefineGraphObj();
            refresh();
            float t = 1f;
        }

        public Series Series1 {  get; set; }
        public List<float> YList { get; set; }

        private void button1_Click(object sender, EventArgs e)
        {
            if (tb_studentid.TextLength != 0)
            {
                _ = GetTempInfo(tb_studentid.Text);
            }
            refresh();
        }

        public async Task refresh()
        {
            while (true)
            {
                var delayTask = Task.Delay(10000);
                _ = GetTempInfo(tb_studentid.Text);
                await delayTask;

            }
        }

        private void fallDetected()
        {

        }

        public void initGraph()
        {

            // Set palette.
            chart1.Palette = ChartColorPalette.SeaGreen;

            // Set title.
            chart1.Titles.Add(string.Format("Body temperature graph"));

            YList = new List<float>();

           
        }

        public void DefineGraphObj()
        {
            // Add series.
            Series1 = chart1.Series.Add("Line");
            Series1.ChartType = SeriesChartType.Line;
            Series1.MarkerSize = 10;
        }

        public void PlotGraph(float temp)
        {

            Series1.Points.Clear();
            int cnt = 0;
            YList.Add(temp);
            foreach(var y in YList)
            {
                Series1.Points.AddXY(cnt, y);
                cnt++;
            }
        }



        private async Task GetTempInfo(String studentid)
        {

            pictureBox1.Hide();
            string getmsg = $"http://localhost:1880/get?studentid={studentid}"; //Assuming node-RED is running on a local instance. Change if node-RED is on a remote instance
            var httpresponse = await client.GetStringAsync(getmsg);
            if (httpresponse != null)
            {

                label9.Hide();
                List<Information> resplist = JsonConvert.DeserializeObject<List<Information>>(httpresponse);
                if (resplist != null)
                {
                    if (resplist.Count == 0)
                    {
                        tb_name.Text = "NOT FOUND";
                        tb_time.Text = "";
                        tb_body.Text = "--°C";
                    }
                    else
                    {
                        var latest_item = new Information();
                        foreach (var item in resplist)
                        {
                            if (item.body != 0 && latest_item.updatetime < item.updatetime)             //Get the latest information based on updatetime
                            {
                                latest_item = item;
                            }
                        }
                        tb_name.Text = latest_item.name;
                        tb_time.Text = latest_item.updatetime.ToLocalTime().ToString();
                        tb_body.Text = latest_item.body.ToString() + "°C";
                        tb_Fall.Text = latest_item.fall.ToString();
                        if (latest_item.fall)
                        {
                            pictureBox1.Show();

                            PopupNotifier popup = new PopupNotifier();
                            popup.BodyColor = Color.Red;
                            popup.TitleText = "Fall Detected!!";
                            popup.TitleColor = Color.Black;
                            popup.TitleFont = new Font("Century Gothic", 13, FontStyle.Bold);

                            popup.ContentText = string.Format("{0} may have fallen and/or needs help!!!", tb_studentid);
                            popup.ContentColor = Color.White;
                            popup.ContentFont = new Font("Century Gothic", 9);
                            popup.Popup();
                        }
                        if (latest_item.body > 38)
                        {
                            PopupNotifier popup = new PopupNotifier();
                            popup.BodyColor = Color.Yellow;
                            popup.TitleText = "Fever detected";
                            popup.TitleColor = Color.Black;
                            popup.TitleFont = new Font("Century Gothic", 13, FontStyle.Bold);

                            popup.ContentText = string.Format("A fever was detected from {0}'s device! ", tb_studentid);
                            popup.ContentColor = Color.Black;
                            popup.ContentFont = new Font("Century Gothic", 9);
                            popup.Popup();
                        }

                        PlotGraph(latest_item.body);

                           

                        
                    }
                }
            }
            else
            {
                label9.Show();
            }
        }



        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label9_Click(object sender, EventArgs e)
        {

        }

        private void tb_name_TextChanged(object sender, EventArgs e)
        {

        }

        private void tb_time_TextChanged(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void chart1_Click(object sender, EventArgs e)
        {

        }
    }
    
}

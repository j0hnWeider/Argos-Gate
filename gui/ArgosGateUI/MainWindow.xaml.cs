using System.Collections.ObjectModel;
using System.Windows;

namespace ArgosGateUI
{
    /// <summary>
    /// Interação lógica para MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public ObservableCollection<ProcessInfo> Processos { get; set; }

        public MainWindow()
        {
            InitializeComponent();
            Processos = new ObservableCollection<ProcessInfo>();
            ProcessListView.ItemsSource = Processos;

            // Exemplo de dados iniciais
            Processos.Add(new ProcessInfo { PID = 1234, ProcessName = "explorer.exe", Status = "Normal" });
            Processos.Add(new ProcessInfo { PID = 5678, ProcessName = "notepad.exe", Status = "Suspeito" });
        }
    }

    public class ProcessInfo
    {
        public int PID { get; set; }
        public string ProcessName { get; set; }
        public string Status { get; set; }
    }
}

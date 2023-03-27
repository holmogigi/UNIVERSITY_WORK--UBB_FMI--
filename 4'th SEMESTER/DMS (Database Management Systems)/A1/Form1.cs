using Microsoft.Data.SqlClient;
using System.Data;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace A1
{
    public partial class Form1 : Form
    {
        private SqlConnection dbConnection;
        private SqlDataAdapter daManagers, daEmployee;
        private DataSet tableData;
        private DataRelation drManagerEmployee;
        BindingSource bsManagers, bsEmployee;

        public Form1()
        {
            InitializeComponent();
        }

        private void ReloadEmployeeTableView()
        {
            if (tableData.Tables["Employee"] != null)
            {
                tableData.Tables["Employee"].Clear();
            }
            daEmployee.Fill(tableData, "Employee");
            EmployeeView.DataSource = bsEmployee;
        }

        private void ManagersView_SelectionChanged(object sender, EventArgs e)
        {
            EmployeeIdText.Clear();
            managerIdText.Clear();
            nameText.Clear();
            phoneText.Clear();
            emailText.Clear();
            PerformanceText.Clear();
            TimeText.Clear();
            salaryText.Clear();
            if (ManagersView.SelectedRows.Count != 0)
            {
                DataGridViewRow selectedRow = ManagersView.SelectedRows[0];
                daEmployee.SelectCommand = new SqlCommand("SELECT * FROM Employee WHERE manager_id = " + selectedRow.Cells[0].Value, dbConnection);
                ReloadEmployeeTableView();
            }
        }

        private void EmployeeView_SelectionChanged(object sender, EventArgs e)
        {
            if (EmployeeView.SelectedRows.Count != 0)
            {
                DataGridViewRow selectedRow = EmployeeView.SelectedRows[0];
                EmployeeIdText.Text = selectedRow.Cells[0].Value.ToString();
                managerIdText.Text = selectedRow.Cells[1].Value.ToString();
                nameText.Text = selectedRow.Cells[2].Value.ToString();
                phoneText.Text = selectedRow.Cells[3].Value.ToString();
                emailText.Text = selectedRow.Cells[4].Value.ToString();
                PerformanceText.Text = selectedRow.Cells[5].Value.ToString();
                TimeText.Text = selectedRow.Cells[6].Value.ToString();
                salaryText.Text = selectedRow.Cells[7].Value.ToString();
            }
        }

        private void addButton_Click(object sender, EventArgs e)
        {
            SqlCommand command = new SqlCommand("INSERT INTO Employee (employee_id, manager_id, employee_name, employee_phone_number, employee_email, prefered_time, type_of_performance, employee_salary) " +
                "VALUES (@EmployeeID, @ManagerID, @EmployeeName, @EmployeePhoneNumber, @EmployeeEmail, @PreferedTime, @TypeOfPerformance, @EmployeeSalary)", dbConnection);
            if (EmployeeIdText.Text.Length != 0)
            {
                try
                {
                    int employee_id = Int32.Parse(EmployeeIdText.Text);
                    if (managerIdText.Text.Length != 0)
                    {
                        int manager_id = Int32.Parse(managerIdText.Text);
                        int salary;
                        if (salaryText.Text.Length != 0)
                            salary = Int32.Parse(salaryText.Text);
                        else
                            salary = 0;
                        command.Parameters.Add("@EmployeeID", SqlDbType.Int);
                        command.Parameters["@EmployeeID"].Value = employee_id;
                        command.Parameters.Add("@ManagerID", SqlDbType.Int);
                        command.Parameters["@ManagerID"].Value = manager_id;
                        command.Parameters.Add("@EmployeeName", SqlDbType.VarChar, 50);
                        command.Parameters["@EmployeeName"].Value = nameText.Text;
                        command.Parameters.Add("@EmployeePhoneNumber", SqlDbType.VarChar, 10);
                        command.Parameters["@EmployeePhoneNumber"].Value = phoneText.Text;
                        command.Parameters.Add("@EmployeeEmail", SqlDbType.VarChar, 50);
                        command.Parameters["@EmployeeEmail"].Value = emailText.Text;
                        command.Parameters.Add("@PreferedTime", SqlDbType.VarChar, 25);
                        command.Parameters["@PreferedTime"].Value = TimeText.Text;
                        command.Parameters.Add("@TypeOfPerformance", SqlDbType.VarChar, 25);
                        command.Parameters["@TypeOfPerformance"].Value = PerformanceText.Text;
                        command.Parameters.Add("@EmployeeSalary", SqlDbType.Int);
                        command.Parameters["@EmployeeSalary"].Value = salary;
                        try
                        {
                            daEmployee.InsertCommand = command;
                            daEmployee.InsertCommand.ExecuteNonQuery();
                            ReloadEmployeeTableView();
                        }
                        catch (SqlException sqlException)
                        {
                            if (sqlException.Number == 2627)
                                MessageBox.Show("!ERROR! Not unique!"); 
                            else if (sqlException.Number == 547)
                                MessageBox.Show("!ERROR! Id not found!");
                            else
                                MessageBox.Show(sqlException.Message);
                        }
                    }
                    else
                        MessageBox.Show("!ERROR! Manager id needed!");
                }
                catch (FormatException ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
            else
                MessageBox.Show("!ERROR! Employee id needed!");
        }

        private void removeButton_Click(object sender, EventArgs e)
        {
            SqlCommand command = new SqlCommand("DELETE FROM Employee WHERE employee_id = @EmployeeID", dbConnection);
            if (EmployeeIdText.Text.Length != 0)
            {
                int Employee_id = Int32.Parse(EmployeeIdText.Text);
                command.Parameters.Add("@EmployeeID", SqlDbType.Int);
                command.Parameters["@EmployeeID"].Value = Employee_id;
                try
                {
                    daEmployee.DeleteCommand = command;
                    int numberOfDeletedEmployee = daEmployee.DeleteCommand.ExecuteNonQuery();
                    if (numberOfDeletedEmployee == 0)
                    {
                        MessageBox.Show("!ERROR! Id not found!");
                    }
                    else
                    {
                        ReloadEmployeeTableView();
                    }
                }
                catch (SqlException sqlException)
                {
                    MessageBox.Show(sqlException.ToString());
                }
            }
            else
                MessageBox.Show("!ERROR! Employee id needed!");
        }

        private void EmployeeView_DataError(object sender, DataGridViewDataErrorEventArgs e)
        {
            if (e.Exception is InvalidConstraintException)
                MessageBox.Show("!ERROR! Id not found!");
            else if (e.Exception is FormatException)
                MessageBox.Show(e.Exception.Message);
            else
                try
                {
                    throw e.Exception;
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.ToString());
                }
        }

        private void updateButton_Click(object sender, EventArgs e)
        {

            SqlCommand command = new SqlCommand("UPDATE Employee " +
                "SET manager_id = @EmployeeID, employee_name = @EmployeeName, employee_phone_number = @EmployeePhoneNumber, " +
                "employee_email = @EmployeeEmail, prefered_time = @PreferedTime, type_of_performance = @TypeOfPerformance, employee_salary = @EmployeeSalary " +
                "WHERE employee_id = @EmployeeID", dbConnection);
            int employee_id = Int32.Parse(EmployeeIdText.Text);
            int manager_id = Int32.Parse(managerIdText.Text);
            int salary = Int32.Parse(salaryText.Text);
            command.Parameters.Add("@EmployeeID", SqlDbType.Int);
            command.Parameters["@EmployeeID"].Value = employee_id;
            command.Parameters.Add("@ManagerID", SqlDbType.Int);
            command.Parameters["@ManagerID"].Value = manager_id;
            command.Parameters.Add("@EmployeeName", SqlDbType.VarChar, 50);
            command.Parameters["@EmployeeName"].Value = nameText.Text;
            command.Parameters.Add("@EmployeePhoneNumber", SqlDbType.VarChar, 10);
            command.Parameters["@EmployeePhoneNumber"].Value = phoneText.Text;
            command.Parameters.Add("@EmployeeEmail", SqlDbType.VarChar, 50);
            command.Parameters["@EmployeeEmail"].Value = emailText.Text;
            command.Parameters.Add("@PreferedTime", SqlDbType.VarChar, 25);
            command.Parameters["@PreferedTime"].Value = TimeText.Text;
            command.Parameters.Add("@TypeOfPerformance", SqlDbType.VarChar, 25);
            command.Parameters["@TypeOfPerformance"].Value = PerformanceText.Text;
            command.Parameters.Add("@EmployeeSalary", SqlDbType.Int);
            command.Parameters["@EmployeeSalary"].Value = salary;
            try
            {
                daEmployee.UpdateCommand = command;
                int numberOfUpdatedSingers = daEmployee.UpdateCommand.ExecuteNonQuery();
                if (numberOfUpdatedSingers != 0)
                {
                    ReloadEmployeeTableView();
                }
                else
                {
                    MessageBox.Show("!ERROR! Id not found!");
                }
            }
            catch (SqlException sqlException)
            {
                if (sqlException.Number == 2627)
                    MessageBox.Show("!ERROR! Not unique!");
                else if (sqlException.Number == 547)
                    MessageBox.Show("!ERROR! Id not found!");
                else
                    MessageBox.Show(sqlException.Message);
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            dbConnection = new SqlConnection("Server=HOLMOGIGI\\SQLEXPRESS;Database=GymEquipSuppStore;Trusted_Connection=True;TrustServerCertificate=True;MultipleActiveResultSets=True;");
            dbConnection.Open();

            daManagers = new SqlDataAdapter("SELECT * FROM Manager", dbConnection);
            tableData = new DataSet();
            daManagers.Fill(tableData, "Manager");
            ManagersView.SelectionMode = DataGridViewSelectionMode.FullRowSelect;

            daEmployee = new SqlDataAdapter("SELECT * FROM Employee", dbConnection);
            daEmployee.Fill(tableData, "Employee");
            EmployeeView.SelectionMode = DataGridViewSelectionMode.FullRowSelect;

            DataColumn managerIdManager = tableData.Tables["Manager"].Columns["manager_id"];
            DataColumn managerIdEmployee = tableData.Tables["Employee"].Columns["manager_id"];
            drManagerEmployee = new DataRelation("FK_MANAGER_EMPLOYEE", managerIdManager, managerIdEmployee);
            tableData.Relations.Add(drManagerEmployee);

            bsManagers = new BindingSource();
            bsManagers.DataSource = tableData;
            bsManagers.DataMember = "Manager";

            bsEmployee = new BindingSource();
            bsEmployee.DataSource = bsManagers;
            bsEmployee.DataMember = "FK_MANAGER_EMPLOYEE";
            ManagersView.DataSource = bsManagers;
        }

      
    }
}
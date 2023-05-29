using Microsoft.Data.SqlClient;
using System.Data;
using static System.Runtime.InteropServices.JavaScript.JSType;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Configuration;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace A1
{
    public partial class Form1 : Form
    {
        private SqlConnection dbConnection;
        private SqlDataAdapter daParent, daChild;
        private DataSet tableData;
        private DataRelation drParentChild;
        BindingSource bsParent, bsChild;
        private List<TextBox> textBoxes;

        public Form1()
        {
            textBoxes = new List<TextBox>();
            InitializeComponent();
            loadTextboxes();
        }

        private void ReloadDrinkTypesTableView()
        {
            string childTable = ConfigurationManager.AppSettings["ChildTableName"];
            if (tableData.Tables[childTable] != null)
                tableData.Tables[childTable].Clear();

            daChild.Fill(tableData, childTable);
            dgChild.DataSource = bsChild;

        }

        private void loadTextboxes()
        {
            try
            {
                // We create a list of strings which contains the columnNames
                // The columnNames are splitted by ','
                List<string> ColumnNames = new List<string>(ConfigurationManager.AppSettings["ColumnNames"].Split(','));

                // We fix 2 points for X and Y, in order to place the textBoxes
                int pointX = 430;
                int pointY = 470;

                ////We take the number of columns and we clear the panel, before placing the new textBoxes
                //int numberOfColumns = Convert.ToInt32(ConfigurationManager.AppSettings["NumberOfColumns"]);
                panel.Controls.Clear();

                foreach (string columnName in ColumnNames)
                {
                    // We create a new textbox
                    TextBox a = new TextBox();
                    textBoxes.Add(a);
                    a.Text = columnName;
                    a.Name = columnName;
                    a.Location = new Point(pointX, pointY);
                    a.Visible = true;
                    a.Parent = panel;
                    panel.Show();
                    pointY -= 30;
                }
            }
            catch (Exception e)
            {
                MessageBox.Show(e.ToString());
            }

        }

        private void clearTextBoxes()
        {
            foreach (TextBox tb in textBoxes)
            {
                tb.Clear();
            }
        }

        private void ConnectButton_Click_1(object sender, EventArgs e)
        {
            dbConnection = new SqlConnection("Data Source=HOLMOGIGI\\SQLEXPRESS;Initial Catalog=GymEquipSuppStore;Trusted_Connection=True;TrustServerCertificate=True;MultipleActiveResultSets=True;Integrated Security=True");
            dbConnection.Open();

            string selectParent = ConfigurationManager.AppSettings["ParentSelectQuery"];
            string parentTable = ConfigurationManager.AppSettings["ParentTableName"];

            daParent = new SqlDataAdapter(selectParent, dbConnection);
            tableData = new DataSet();
            daParent.Fill(tableData, parentTable);
            dgParent.SelectionMode = DataGridViewSelectionMode.FullRowSelect;

            string selectChild = ConfigurationManager.AppSettings["ChildSelectQuery"];
            string childTable = ConfigurationManager.AppSettings["ChildTableName"];

            daChild = new SqlDataAdapter(selectChild, dbConnection);
            daChild.Fill(tableData, childTable);
            dgChild.SelectionMode = DataGridViewSelectionMode.FullRowSelect;

            string fk = ConfigurationManager.AppSettings["ChildForeignKey"];
            DataColumn managerIdParent = tableData.Tables[parentTable].Columns[fk];
            DataColumn managerIdChild = tableData.Tables[childTable].Columns[fk];

            string foreingKey = ConfigurationManager.AppSettings["ForeingKey"];
            drParentChild = new DataRelation(foreingKey, managerIdParent, managerIdChild);
            tableData.Relations.Add(drParentChild);

            bsParent = new BindingSource();
            bsParent.DataSource = tableData;
            bsParent.DataMember = parentTable;

            bsChild = new BindingSource();
            bsChild.DataSource = bsParent;
            bsChild.DataMember = foreingKey;
            dgParent.DataSource = bsParent;

        }
    

        private void AddButton_Click(object sender, EventArgs e)
        {
            try
            {
                // We take the insert command
                string insertCommand = ConfigurationSettings.AppSettings["InsertQuery"];

                // We create the insert command
                this.daChild.InsertCommand = new SqlCommand(insertCommand, this.dbConnection);

                // We take the childTable's name
                string childTableName = ConfigurationManager.AppSettings["ChildTableName"];

                // We create a list with the column names of the child table which are splited by ','

                List<string> columnNamesList = new List<string>(ConfigurationManager.AppSettings["ColumnNames"].Split(','));

                // We go throguh all these columnNames
                // And then we parse the list of textBoxes in order to find the one whose name is the same as the columnName 
                foreach (string columnName in columnNamesList)
                {
                    foreach (TextBox tb in this.textBoxes)
                    {
                        if (tb.Name == columnName)
                        {
                            // After we find it, we insert to the coresponding parameter, the text from the textBox 
                            this.daChild.InsertCommand.Parameters.AddWithValue("@" + columnName, tb.Text);
                        }
                    }
                }

                // We open the connection and execute the query
                //this.dbConnection.Open();
                this.daChild.InsertCommand.ExecuteNonQuery();

                MessageBox.Show("Inserted with succes!");

                // We update the child table
                this.tableData = new DataSet();
                this.daChild.Fill(this.tableData, childTableName);
                this.dgChild.DataSource = this.tableData.Tables[childTableName];

                this.clearTextBoxes();

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                this.dbConnection.Close();
            }

        }

        private void RemoveButton_Click(object sender, EventArgs e)
        {
            string childId = ConfigurationManager.AppSettings["ChildId"];

            SqlCommand command = new SqlCommand("DELETE FROM " + ConfigurationManager.AppSettings["ChildTableName"] +
                " WHERE " + childId + "= @" + childId, dbConnection);

            foreach (TextBox tb in textBoxes)
            {
                if (tb.Name == childId)
                {
                    if (tb.Text.Length != 0)
                    {
                        int id = Int32.Parse(tb.Text);
                        command.Parameters.Add("@" + childId, SqlDbType.Int);
                        command.Parameters["@" + childId].Value = id;

                        try
                        {
                            daChild.DeleteCommand = command;
                            int numberofdeleted = daChild.DeleteCommand.ExecuteNonQuery();
                            if (numberofdeleted > 0)
                            {
                                MessageBox.Show("Deleted successfully!");
                                ReloadDrinkTypesTableView();
                            }
                            else
                            {
                                MessageBox.Show("No record with given id found!");
                            }
                        }
                        catch (SqlException ex)
                        {
                            MessageBox.Show(ex.ToString());
                        }
                    }
                    else
                    {
                        MessageBox.Show("Please input id");
                    }
                    break;
                }
            }

        }


        private void UpdateButton_Click(object sender, EventArgs e)
        {
            try
            {
                string updateCommand = ConfigurationManager.AppSettings["UpdateQuery"];

                this.daChild.UpdateCommand = new SqlCommand(updateCommand, this.dbConnection);

                string childTableName = ConfigurationManager.AppSettings["ChildTableName"];

                List<string> columnNames = new List<string>(ConfigurationManager.AppSettings["ColumnNames"].Split(','));

                foreach (string columnName in columnNames)
                {
                    foreach (TextBox tb in textBoxes)
                    {
                        if (tb.Name == columnName)
                        {
                            this.daChild.UpdateCommand.Parameters.AddWithValue("@" + columnName, tb.Text);
                        }
                    }
                }

                this.daChild.UpdateCommand.ExecuteNonQuery();
                MessageBox.Show("Updated with success");

                this.tableData = new DataSet();
                this.daChild.Fill(this.tableData, childTableName);
                this.dgChild.DataSource = this.tableData.Tables[childTableName];

                foreach (TextBox tb in textBoxes)
                {
                    tb.Clear();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }

        }
      
        private void DistributorsView_SelectionChanged(object sender, EventArgs e)
        {
            if (dgParent.SelectedRows.Count != 0)
            {
                DataGridViewRow selectedRow = dgParent.SelectedRows[0];
                daChild.SelectCommand = new SqlCommand("Select * FROM " +
                    ConfigurationManager.AppSettings["ChildTableName"] +
                    " WHERE " + ConfigurationManager.AppSettings["ParentId"] + "=" + selectedRow.Cells[0].Value, dbConnection);
                ReloadDrinkTypesTableView();
            }
        }


        private void DrinkTypesView_SelectionChanged(System.Object sender, EventArgs e)
        {
            if (dgChild.SelectedRows.Count != 0)
            {
                DataGridViewRow selectedRow = dgChild.SelectedRows[0];
            }
        }


        /*
         * 
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
        
        */
      
    }
}
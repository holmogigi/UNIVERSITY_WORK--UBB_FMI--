namespace A1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            ManagersView = new DataGridView();
            EmployeeView = new DataGridView();
            ManagerLabel = new Label();
            EmployeeLabel = new Label();
            EmployeeIdLabel = new Label();
            ManagerIdLabel = new Label();
            NameLabel = new Label();
            PhoneLabel = new Label();
            EmailLabel = new Label();
            TimeLabel = new Label();
            PerformanceLabel = new Label();
            EmployeeIdText = new TextBox();
            managerIdText = new TextBox();
            nameText = new TextBox();
            phoneText = new TextBox();
            emailText = new TextBox();
            TimeText = new TextBox();
            PerformanceText = new TextBox();
            SalaryLabel = new Label();
            salaryText = new TextBox();
            addButton = new Button();
            removeButton = new Button();
            updateButton = new Button();
            tableLayoutPanel1 = new TableLayoutPanel();
            tableLayoutPanel2 = new TableLayoutPanel();
            tableLayoutPanel3 = new TableLayoutPanel();
            ((System.ComponentModel.ISupportInitialize)ManagersView).BeginInit();
            ((System.ComponentModel.ISupportInitialize)EmployeeView).BeginInit();
            tableLayoutPanel1.SuspendLayout();
            tableLayoutPanel2.SuspendLayout();
            tableLayoutPanel3.SuspendLayout();
            SuspendLayout();
            // 
            // ManagersView
            // 
            ManagersView.AllowUserToAddRows = false;
            ManagersView.AllowUserToDeleteRows = false;
            ManagersView.BackgroundColor = Color.White;
            ManagersView.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            ManagersView.Dock = DockStyle.Fill;
            ManagersView.Location = new Point(3, 19);
            ManagersView.Margin = new Padding(3, 2, 3, 2);
            ManagersView.Name = "ManagersView";
            ManagersView.ReadOnly = true;
            ManagersView.RowHeadersWidth = 51;
            ManagersView.RowTemplate.Height = 24;
            ManagersView.Size = new Size(561, 413);
            ManagersView.TabIndex = 0;
            ManagersView.SelectionChanged += ManagersView_SelectionChanged;
            // 
            // EmployeeView
            // 
            EmployeeView.AllowUserToAddRows = false;
            EmployeeView.AllowUserToDeleteRows = false;
            EmployeeView.BackgroundColor = Color.Snow;
            EmployeeView.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            EmployeeView.Dock = DockStyle.Fill;
            EmployeeView.Location = new Point(570, 19);
            EmployeeView.Margin = new Padding(3, 2, 3, 2);
            EmployeeView.Name = "EmployeeView";
            EmployeeView.RowHeadersWidth = 51;
            EmployeeView.RowTemplate.Height = 24;
            EmployeeView.Size = new Size(504, 413);
            EmployeeView.TabIndex = 1;
            EmployeeView.DataError += EmployeeView_DataError;
            EmployeeView.SelectionChanged += EmployeeView_SelectionChanged;
            // 
            // ManagerLabel
            // 
            ManagerLabel.AutoSize = true;
            ManagerLabel.Dock = DockStyle.Fill;
            ManagerLabel.Font = new Font("Microsoft YaHei UI", 9F, FontStyle.Regular, GraphicsUnit.Point);
            ManagerLabel.Location = new Point(3, 0);
            ManagerLabel.Name = "ManagerLabel";
            ManagerLabel.Size = new Size(561, 17);
            ManagerLabel.TabIndex = 2;
            ManagerLabel.Text = "Managers"; 
            // 
            // EmployeeLabel
            // 
            EmployeeLabel.AutoSize = true;
            EmployeeLabel.Dock = DockStyle.Fill;
            EmployeeLabel.Font = new Font("Microsoft YaHei UI", 9F, FontStyle.Regular, GraphicsUnit.Point);
            EmployeeLabel.Location = new Point(570, 0);
            EmployeeLabel.Name = "EmployeeLabel";
            EmployeeLabel.Size = new Size(504, 17);
            EmployeeLabel.TabIndex = 3;
            EmployeeLabel.Text = "Employee";
            // 
            // EmployeeIdLabel
            // 
            EmployeeIdLabel.AutoSize = true;
            EmployeeIdLabel.Dock = DockStyle.Fill;
            EmployeeIdLabel.Font = new Font("Microsoft YaHei UI", 9F, FontStyle.Regular, GraphicsUnit.Point);
            EmployeeIdLabel.Location = new Point(3, 0);
            EmployeeIdLabel.Name = "EmployeeIdLabel";
            EmployeeIdLabel.Size = new Size(111, 27);
            EmployeeIdLabel.TabIndex = 4;
            EmployeeIdLabel.Text = "Employee ID";
            // 
            // ManagerIdLabel
            // 
            ManagerIdLabel.AutoSize = true;
            ManagerIdLabel.Dock = DockStyle.Fill;
            ManagerIdLabel.Font = new Font("Microsoft YaHei", 9F, FontStyle.Regular, GraphicsUnit.Point);
            ManagerIdLabel.Location = new Point(322, 0);
            ManagerIdLabel.Name = "ManagerIdLabel";
            ManagerIdLabel.Size = new Size(96, 27);
            ManagerIdLabel.TabIndex = 5;
            ManagerIdLabel.Text = "Manager ID";
            // 
            // NameLabel
            // 
            NameLabel.AutoSize = true;
            NameLabel.Dock = DockStyle.Left;
            NameLabel.Font = new Font("Microsoft YaHei UI", 9F, FontStyle.Regular, GraphicsUnit.Point);
            NameLabel.Location = new Point(3, 27);
            NameLabel.Name = "NameLabel";
            NameLabel.Size = new Size(43, 27);
            NameLabel.TabIndex = 6;
            NameLabel.Text = "Name";
            // 
            // PhoneLabel
            // 
            PhoneLabel.AutoSize = true;
            PhoneLabel.Dock = DockStyle.Fill;
            PhoneLabel.Font = new Font("Microsoft YaHei UI", 9F, FontStyle.Regular, GraphicsUnit.Point);
            PhoneLabel.Location = new Point(322, 27);
            PhoneLabel.Name = "PhoneLabel";
            PhoneLabel.Size = new Size(96, 27);
            PhoneLabel.TabIndex = 7;
            PhoneLabel.Text = "Phone Number";
            // 
            // EmailLabel
            // 
            EmailLabel.AutoSize = true;
            EmailLabel.Dock = DockStyle.Left;
            EmailLabel.Font = new Font("Microsoft YaHei UI", 9F, FontStyle.Regular, GraphicsUnit.Point);
            EmailLabel.Location = new Point(3, 54);
            EmailLabel.Name = "EmailLabel";
            EmailLabel.Size = new Size(39, 27);
            EmailLabel.TabIndex = 8;
            EmailLabel.Text = "Email";
            // 
            // TimeLabel
            // 
            TimeLabel.AutoSize = true;
            TimeLabel.Dock = DockStyle.Fill;
            TimeLabel.Font = new Font("Microsoft YaHei UI", 9F, FontStyle.Regular, GraphicsUnit.Point);
            TimeLabel.Location = new Point(322, 54);
            TimeLabel.Name = "TimeLabel";
            TimeLabel.Size = new Size(96, 27);
            TimeLabel.TabIndex = 9;
            TimeLabel.Text = "Prefered Time";
            // 
            // PerformanceLabel
            // 
            PerformanceLabel.AutoSize = true;
            PerformanceLabel.Dock = DockStyle.Left;
            PerformanceLabel.Font = new Font("Microsoft YaHei UI", 9F, FontStyle.Regular, GraphicsUnit.Point);
            PerformanceLabel.Location = new Point(3, 81);
            PerformanceLabel.Name = "PerformanceLabel";
            PerformanceLabel.Size = new Size(111, 88);
            PerformanceLabel.TabIndex = 10;
            PerformanceLabel.Text = "Performance type";
            // 
            // EmployeeIdText
            // 
            EmployeeIdText.Dock = DockStyle.Left;
            EmployeeIdText.Location = new Point(120, 2);
            EmployeeIdText.Margin = new Padding(3, 2, 3, 2);
            EmployeeIdText.Name = "EmployeeIdText";
            EmployeeIdText.Size = new Size(88, 23);
            EmployeeIdText.TabIndex = 11;
            // 
            // managerIdText
            // 
            managerIdText.Dock = DockStyle.Left;
            managerIdText.Location = new Point(424, 2);
            managerIdText.Margin = new Padding(3, 2, 3, 2);
            managerIdText.Name = "managerIdText";
            managerIdText.Size = new Size(88, 23);
            managerIdText.TabIndex = 12;
            // 
            // nameText
            // 
            nameText.Dock = DockStyle.Left;
            nameText.Location = new Point(120, 29);
            nameText.Margin = new Padding(3, 2, 3, 2);
            nameText.Name = "nameText";
            nameText.Size = new Size(168, 23);
            nameText.TabIndex = 13;
            // 
            // phoneText
            // 
            phoneText.Dock = DockStyle.Left;
            phoneText.Location = new Point(424, 29);
            phoneText.Margin = new Padding(3, 2, 3, 2);
            phoneText.Name = "phoneText";
            phoneText.Size = new Size(123, 23);
            phoneText.TabIndex = 14;
            // 
            // emailText
            // 
            emailText.Dock = DockStyle.Left;
            emailText.Location = new Point(120, 56);
            emailText.Margin = new Padding(3, 2, 3, 2);
            emailText.Name = "emailText";
            emailText.Size = new Size(196, 23);
            emailText.TabIndex = 15;
            // 
            // TimeText
            // 
            TimeText.Dock = DockStyle.Left;
            TimeText.Location = new Point(120, 83);
            TimeText.Margin = new Padding(3, 2, 3, 2);
            TimeText.Name = "TimeText";
            TimeText.Size = new Size(88, 23);
            TimeText.TabIndex = 16;
            // 
            // PerformanceText
            // 
            PerformanceText.Dock = DockStyle.Left;
            PerformanceText.Location = new Point(424, 56);
            PerformanceText.Margin = new Padding(3, 2, 3, 2);
            PerformanceText.Name = "PerformanceText";
            PerformanceText.Size = new Size(123, 23);
            PerformanceText.TabIndex = 17;
            // 
            // SalaryLabel
            // 
            SalaryLabel.AutoSize = true;
            SalaryLabel.Dock = DockStyle.Fill;
            SalaryLabel.Font = new Font("Microsoft YaHei UI", 9F, FontStyle.Regular, GraphicsUnit.Point);
            SalaryLabel.Location = new Point(322, 81);
            SalaryLabel.Name = "SalaryLabel";
            SalaryLabel.Size = new Size(96, 88);
            SalaryLabel.TabIndex = 18;
            SalaryLabel.Text = "Salary";
            // 
            // salaryText
            // 
            salaryText.Dock = DockStyle.Left;
            salaryText.Location = new Point(424, 83);
            salaryText.Margin = new Padding(3, 2, 3, 2);
            salaryText.Name = "salaryText";
            salaryText.Size = new Size(88, 23);
            salaryText.TabIndex = 19;
            // 
            // addButton
            // 
            addButton.BackColor = Color.RosyBrown;
            addButton.Dock = DockStyle.Left;
            addButton.FlatAppearance.BorderColor = Color.RosyBrown;
            addButton.Font = new Font("Microsoft YaHei UI", 9F, FontStyle.Regular, GraphicsUnit.Point);
            addButton.ForeColor = SystemColors.ActiveCaptionText;
            addButton.Location = new Point(3, 2);
            addButton.Margin = new Padding(3, 2, 3, 2);
            addButton.Name = "addButton";
            addButton.Size = new Size(196, 51);
            addButton.TabIndex = 20;
            addButton.Text = "Add Employee";
            addButton.UseVisualStyleBackColor = false;
            addButton.Click += addButton_Click;
            // 
            // removeButton
            // 
            removeButton.BackColor = Color.RosyBrown;
            removeButton.Dock = DockStyle.Left;
            removeButton.Font = new Font("Microsoft YaHei UI", 9F, FontStyle.Regular, GraphicsUnit.Point);
            removeButton.Location = new Point(3, 57);
            removeButton.Margin = new Padding(3, 2, 3, 2);
            removeButton.Name = "removeButton";
            removeButton.Size = new Size(196, 50);
            removeButton.TabIndex = 21;
            removeButton.Text = "Remove Employee";
            removeButton.UseVisualStyleBackColor = false;
            removeButton.Click += removeButton_Click;
            // 
            // updateButton
            // 
            updateButton.BackColor = Color.RosyBrown;
            updateButton.Dock = DockStyle.Left;
            updateButton.Font = new Font("Microsoft YaHei UI", 9F, FontStyle.Regular, GraphicsUnit.Point);
            updateButton.Location = new Point(3, 111);
            updateButton.Margin = new Padding(3, 2, 3, 2);
            updateButton.Name = "updateButton";
            updateButton.Size = new Size(196, 58);
            updateButton.TabIndex = 22;
            updateButton.Text = "Update Employee";
            updateButton.UseVisualStyleBackColor = false;
            updateButton.Click += updateButton_Click;
            // 
            // tableLayoutPanel1
            // 
            tableLayoutPanel1.ColumnCount = 2;
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 52.72136F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 47.27864F));
            tableLayoutPanel1.Controls.Add(ManagerLabel, 0, 0);
            tableLayoutPanel1.Controls.Add(EmployeeLabel, 1, 0);
            tableLayoutPanel1.Controls.Add(ManagersView, 0, 1);
            tableLayoutPanel1.Controls.Add(EmployeeView, 1, 1);
            tableLayoutPanel1.Controls.Add(tableLayoutPanel2, 0, 2);
            tableLayoutPanel1.Controls.Add(tableLayoutPanel3, 1, 2);
            tableLayoutPanel1.Dock = DockStyle.Fill;
            tableLayoutPanel1.Location = new Point(0, 0);
            tableLayoutPanel1.Margin = new Padding(3, 2, 3, 2);
            tableLayoutPanel1.Name = "tableLayoutPanel1";
            tableLayoutPanel1.RowCount = 3;
            tableLayoutPanel1.RowStyles.Add(new RowStyle());
            tableLayoutPanel1.RowStyles.Add(new RowStyle());
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Absolute, 19F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Absolute, 19F));
            tableLayoutPanel1.Size = new Size(1077, 607);
            tableLayoutPanel1.TabIndex = 23;
            // 
            // tableLayoutPanel2
            // 
            tableLayoutPanel2.ColumnCount = 4;
            tableLayoutPanel2.ColumnStyles.Add(new ColumnStyle());
            tableLayoutPanel2.ColumnStyles.Add(new ColumnStyle());
            tableLayoutPanel2.ColumnStyles.Add(new ColumnStyle());
            tableLayoutPanel2.ColumnStyles.Add(new ColumnStyle());
            tableLayoutPanel2.Controls.Add(NameLabel, 0, 1);
            tableLayoutPanel2.Controls.Add(EmployeeIdLabel, 0, 0);
            tableLayoutPanel2.Controls.Add(EmployeeIdText, 1, 0);
            tableLayoutPanel2.Controls.Add(salaryText, 3, 3);
            tableLayoutPanel2.Controls.Add(ManagerIdLabel, 2, 0);
            tableLayoutPanel2.Controls.Add(SalaryLabel, 2, 3);
            tableLayoutPanel2.Controls.Add(managerIdText, 3, 0);
            tableLayoutPanel2.Controls.Add(TimeText, 1, 3);
            tableLayoutPanel2.Controls.Add(nameText, 1, 1);
            tableLayoutPanel2.Controls.Add(PerformanceLabel, 0, 3);
            tableLayoutPanel2.Controls.Add(PerformanceText, 3, 2);
            tableLayoutPanel2.Controls.Add(PhoneLabel, 2, 1);
            tableLayoutPanel2.Controls.Add(emailText, 1, 2);
            tableLayoutPanel2.Controls.Add(TimeLabel, 2, 2);
            tableLayoutPanel2.Controls.Add(phoneText, 3, 1);
            tableLayoutPanel2.Controls.Add(EmailLabel, 0, 2);
            tableLayoutPanel2.Dock = DockStyle.Fill;
            tableLayoutPanel2.Location = new Point(3, 436);
            tableLayoutPanel2.Margin = new Padding(3, 2, 3, 2);
            tableLayoutPanel2.Name = "tableLayoutPanel2";
            tableLayoutPanel2.RowCount = 4;
            tableLayoutPanel2.RowStyles.Add(new RowStyle());
            tableLayoutPanel2.RowStyles.Add(new RowStyle());
            tableLayoutPanel2.RowStyles.Add(new RowStyle());
            tableLayoutPanel2.RowStyles.Add(new RowStyle());
            tableLayoutPanel2.Size = new Size(561, 169);
            tableLayoutPanel2.TabIndex = 4;
            // 
            // tableLayoutPanel3
            // 
            tableLayoutPanel3.ColumnCount = 1;
            tableLayoutPanel3.ColumnStyles.Add(new ColumnStyle());
            tableLayoutPanel3.Controls.Add(updateButton, 0, 2);
            tableLayoutPanel3.Controls.Add(addButton, 0, 0);
            tableLayoutPanel3.Controls.Add(removeButton, 0, 1);
            tableLayoutPanel3.Dock = DockStyle.Fill;
            tableLayoutPanel3.Location = new Point(570, 436);
            tableLayoutPanel3.Margin = new Padding(3, 2, 3, 2);
            tableLayoutPanel3.Name = "tableLayoutPanel3";
            tableLayoutPanel3.RowCount = 3;
            tableLayoutPanel3.RowStyles.Add(new RowStyle());
            tableLayoutPanel3.RowStyles.Add(new RowStyle());
            tableLayoutPanel3.RowStyles.Add(new RowStyle());
            tableLayoutPanel3.Size = new Size(504, 169);
            tableLayoutPanel3.TabIndex = 5;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.AppWorkspace;
            ClientSize = new Size(1077, 607);
            Controls.Add(tableLayoutPanel1);
            Margin = new Padding(3, 2, 3, 2);
            Name = "Form1";
            Text = "Form1";
            Load += Form1_Load;
            ((System.ComponentModel.ISupportInitialize)ManagersView).EndInit();
            ((System.ComponentModel.ISupportInitialize)EmployeeView).EndInit();
            tableLayoutPanel1.ResumeLayout(false);
            tableLayoutPanel1.PerformLayout();
            tableLayoutPanel2.ResumeLayout(false);
            tableLayoutPanel2.PerformLayout();
            tableLayoutPanel3.ResumeLayout(false);
            ResumeLayout(false);
        }

        #endregion

        private System.Windows.Forms.DataGridView ManagersView;
        private System.Windows.Forms.DataGridView EmployeeView;
        private System.Windows.Forms.Label ManagerLabel;
        private System.Windows.Forms.Label EmployeeLabel;
        private System.Windows.Forms.Label EmployeeIdLabel;
        private System.Windows.Forms.Label ManagerIdLabel;
        private System.Windows.Forms.Label NameLabel;
        private System.Windows.Forms.Label PhoneLabel;
        private System.Windows.Forms.Label EmailLabel;
        private System.Windows.Forms.Label TimeLabel;
        private System.Windows.Forms.Label PerformanceLabel;
        private System.Windows.Forms.TextBox EmployeeIdText;
        private System.Windows.Forms.TextBox managerIdText;
        private System.Windows.Forms.TextBox nameText;
        private System.Windows.Forms.TextBox phoneText;
        private System.Windows.Forms.TextBox emailText;
        private System.Windows.Forms.TextBox TimeText;
        private System.Windows.Forms.TextBox PerformanceText;
        private System.Windows.Forms.Label SalaryLabel;
        private System.Windows.Forms.TextBox salaryText;
        private System.Windows.Forms.Button addButton;
        private System.Windows.Forms.Button removeButton;
        private System.Windows.Forms.Button updateButton;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel2;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel3;
    }
}

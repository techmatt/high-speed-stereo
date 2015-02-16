namespace UIWindow
{
    partial class UIWindow
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
            this.components = new System.ComponentModel.Container();
            this.timerProcessMessages = new System.Windows.Forms.Timer(this.components);
            this.timerInitialize = new System.Windows.Forms.Timer(this.components);
            this.timerDisconnectCheck = new System.Windows.Forms.Timer(this.components);
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.helpBox = new System.Windows.Forms.GroupBox();
            this.textBoxCommands = new System.Windows.Forms.TextBox();
            this.radioButton2DView = new System.Windows.Forms.RadioButton();
            this.radioButton3DView = new System.Windows.Forms.RadioButton();
            this.groupBox1.SuspendLayout();
            this.helpBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // timerProcessMessages
            // 
            this.timerProcessMessages.Enabled = true;
            this.timerProcessMessages.Interval = 1;
            this.timerProcessMessages.Tick += new System.EventHandler(this.timerProcessMessages_Tick);
            // 
            // timerInitialize
            // 
            this.timerInitialize.Enabled = true;
            this.timerInitialize.Tick += new System.EventHandler(this.timerInitialize_Tick);
            // 
            // timerDisconnectCheck
            // 
            this.timerDisconnectCheck.Enabled = true;
            this.timerDisconnectCheck.Interval = 500;
            this.timerDisconnectCheck.Tick += new System.EventHandler(this.timerDisconnectCheck_Tick);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.radioButton3DView);
            this.groupBox1.Controls.Add(this.radioButton2DView);
            this.groupBox1.Location = new System.Drawing.Point(12, 11);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(133, 167);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Mode";
            // 
            // helpBox
            // 
            this.helpBox.Controls.Add(this.textBoxCommands);
            this.helpBox.Location = new System.Drawing.Point(151, 12);
            this.helpBox.Name = "helpBox";
            this.helpBox.Size = new System.Drawing.Size(247, 166);
            this.helpBox.TabIndex = 4;
            this.helpBox.TabStop = false;
            this.helpBox.Text = "Commands";
            // 
            // textBoxCommands
            // 
            this.textBoxCommands.BackColor = System.Drawing.SystemColors.Control;
            this.textBoxCommands.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBoxCommands.Font = new System.Drawing.Font("Calibri", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBoxCommands.Location = new System.Drawing.Point(8, 21);
            this.textBoxCommands.Multiline = true;
            this.textBoxCommands.Name = "textBoxCommands";
            this.textBoxCommands.Size = new System.Drawing.Size(233, 130);
            this.textBoxCommands.TabIndex = 0;
            // 
            // radioButton2DView
            // 
            this.radioButton2DView.AutoSize = true;
            this.radioButton2DView.Location = new System.Drawing.Point(6, 20);
            this.radioButton2DView.Name = "radioButton2DView";
            this.radioButton2DView.Size = new System.Drawing.Size(69, 19);
            this.radioButton2DView.TabIndex = 0;
            this.radioButton2DView.TabStop = true;
            this.radioButton2DView.Text = "2D View";
            this.radioButton2DView.UseVisualStyleBackColor = true;
            this.radioButton2DView.CheckedChanged += new System.EventHandler(this.radioButton2DView_CheckedChanged);
            // 
            // radioButton3DView
            // 
            this.radioButton3DView.AutoSize = true;
            this.radioButton3DView.Location = new System.Drawing.Point(6, 45);
            this.radioButton3DView.Name = "radioButton3DView";
            this.radioButton3DView.Size = new System.Drawing.Size(69, 19);
            this.radioButton3DView.TabIndex = 0;
            this.radioButton3DView.TabStop = true;
            this.radioButton3DView.Text = "3D View";
            this.radioButton3DView.UseVisualStyleBackColor = true;
            // 
            // UIWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(408, 254);
            this.Controls.Add(this.helpBox);
            this.Controls.Add(this.groupBox1);
            this.Font = new System.Drawing.Font("Calibri", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Name = "UIWindow";
            this.Opacity = 0.8D;
            this.Text = "Waiting for connection from application...";
            this.TopMost = true;
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.UIWindow_FormClosing);
            this.Load += new System.EventHandler(this.UIWindow_Load);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.UIWindow_KeyUp);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.helpBox.ResumeLayout(false);
            this.helpBox.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Timer timerProcessMessages;
        private System.Windows.Forms.Timer timerInitialize;
        private System.Windows.Forms.Timer timerDisconnectCheck;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox helpBox;
        private System.Windows.Forms.TextBox textBoxCommands;
        private System.Windows.Forms.RadioButton radioButton3DView;
        private System.Windows.Forms.RadioButton radioButton2DView;
    }
}


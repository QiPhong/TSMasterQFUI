from TSMaster import *
import sys
blacklist = ["tkinter"] # modules such as tkinter will release GIL by itself, which is not allowed in TSMster Toolbox
for mod in blacklist:
    if sys.modules.get(mod):
        tmp_import = __import__ (mod)
        sys.modules[mod] = None

# Auto Generated Python Code, do not modify START [UI] --------------
class _45345(frmTSForm):
    def __init__(self):
        # set type name internally
        self.ExternalTypeName = type(self).__name__
        try:
            # Form properties
            if not self.IsConfigurationLoaded:
                self.Left = 392
                self.Top = 392
                self.Caption = '_45345'
                self.ClientHeight = 502
                self.ClientWidth = 786
            self.Color = clBtnFace
            self.DoubleBuffered = True
            self.Font.Charset = DEFAULT_CHARSET
            self.Font.Color = clWindowText
            self.Font.Height = -12
            self.Font.Name = 'Segoe UI'
            self.Font.Style = []
            self.KeyPreview = True
            self.Position = "poDesigned"
            self.Visible = True
            self.TextHeight = 15
            # Create control: ComboBox1 = ComboBox(self)
            self.ComboBox1 = ComboBox(self)
            self.ComboBox1.Name = "ComboBox1"
            self.ComboBox1.Parent = self
            self.ComboBox1.Left = 200
            self.ComboBox1.Top = 216
            self.ComboBox1.Width = 144
            self.ComboBox1.Height = 23
            self.ComboBox1.Cursor = crArrow
            self.ComboBox1.Style = "csDropDownList"
            self.ComboBox1.TabOrder = 0
            self.ComboBox1.Items.Assign(['如4345435','6867sdfssdf','sdfsdf'])
        finally:
            # End UI auto creation
            self.EndUIAutoCreation()
# Auto Generated Python Code, do not modify END [UI] ----------------
        # your init code starts here...
        self.f()
    def f(self):
        print(212121)
# Auto Generated Python Code, do not modify START [MAIN] ------------
if __name__ == "__main__":
    try:
        _45345().Show()
        Application.Run()
    except SystemExit:
        pass
# Auto Generated Python Code, do not modify END [MAIN] --------------

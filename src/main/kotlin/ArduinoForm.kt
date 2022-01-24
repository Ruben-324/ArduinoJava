import jssc.SerialPort
import java.awt.BorderLayout
import java.util.*
import javax.swing.*
import javax.swing.event.ListSelectionEvent
import javax.swing.event.ListSelectionListener

fun main() {
    Form().isVisible = true
}

class Form(val nombre:String):JFrame(){

    private var laminaList = JPanel()
    private var laminaled = JPanel()

    private lateinit var jList:JList<String>

    private var puerto:String = ""

    private var serialPort = SerialPort(null)

    constructor(): this(nombre = "Arduino Form"){
        title = nombre
        setBounds(0,0, 500, 150)
        setLocationRelativeTo(null)
        defaultCloseOperation = EXIT_ON_CLOSE

        var puertos = ArduinoConection.getPorts()
        jList = JList(puertos)
        jList.visibleRowCount = 3

        var scrollPane = JScrollPane(jList)
        var label = JLabel("Puertos")
        var connectar = JButton("Connectar")
        var salir = JButton("Salir")
        laminaList.add(label)
        laminaList.add(scrollPane)
        laminaList.add(connectar)
        laminaList.add(salir)

        connectar.addActionListener {

            if (puerto.isNotBlank()){
                connectarArduino()
                Thread.sleep(1500)
                jList.isEnabled = false
                connectar.isEnabled = false
            }
            else JOptionPane.
                showMessageDialog(
            this,
            "selecciona un puerto para conectar"
             )
        }

        salir.addActionListener {
            if (serialPort.isOpened){
                serialPort.closePort()
                connectar.isEnabled  =true
                jList.isEnabled = true
            }
            else JOptionPane.showMessageDialog(
                this,
                "tienes que abrir el puerto serial para cerrarlo"
            )
        }

        jList.addListSelectionListener {
            var valores = jList.selectedValuesList
            for (valor in valores){
                println(valor)
                this.puerto = valor
            }

        }


        var texto = JTextField(20)
        var enviar = JButton("Enviar Texto")

        enviar.addActionListener {
            if (serialPort.isOpened) serialPort.writeString(texto.text)
            else JOptionPane.
            showMessageDialog(
                this,
                "No has seleccionado un puerto"
            )
        }

        laminaled.add(texto)
        laminaled.add(enviar)

        add(laminaled, BorderLayout.CENTER)
        add(laminaList, BorderLayout.NORTH)
    }

    fun connectarArduino(){
            var sp = ArduinoConection()
                .Connectar(
                    puerto,
                    SerialPort.BAUDRATE_115200,
                    SerialPort.DATABITS_8,
                    SerialPort.STOPBITS_1,
                    SerialPort.PARITY_NONE
                )
            serialPort = sp
    }

}

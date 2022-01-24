import jssc.SerialPort
import jssc.SerialPortList

class ArduinoConection {

    lateinit var sp:SerialPort

    fun Connectar(
        puerto:String,
        baudrate:Int,
        databits:Int,
        stopbits:Int,
        parity:Int,
    ):SerialPort{
        var sp = SerialPort(puerto)
        sp.openPort()
        sp.setParams(baudrate, databits, stopbits, parity)
        this.sp = sp
        return sp
    }

    fun addEventListener(eventListener:(SerialPort) -> Unit){
        sp.addEventListener {
            eventListener(sp)
        }
    }

    companion object{
        fun getPorts(): Array<String> = SerialPortList.getPortNames()
    }
}
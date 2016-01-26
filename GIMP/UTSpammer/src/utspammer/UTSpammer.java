/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package utspammer;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Gavioli Federico
 */
public class UTSpammer {
    /**
     * @param args the command line arguments
     * @throws java.io.IOException
     */
    public static void main(String[] args) throws IOException {
        DatagramSocket socket = new DatagramSocket();
        Path uno = Paths.get("uno");
        byte[] buf1 = Files.readAllBytes(uno);
        Path due = Paths.get("due");
        byte[] buf2 = Files.readAllBytes(due);
        Path tre = Paths.get("tre");
        byte[] buf3 = Files.readAllBytes(tre);
        Path pingp = Paths.get("ping");
        byte[] buf4 = Files.readAllBytes(pingp);
        InetAddress address = InetAddress.getByName("10.1.6.14");
        DatagramPacket packet1 = new DatagramPacket(buf1, buf1.length, 
                                    address, 7777);
        DatagramPacket packet2 = new DatagramPacket(buf2, buf2.length, 
                                    address, 7777);
        DatagramPacket packet3 = new DatagramPacket(buf3, buf3.length, 
                                    address, 7777);
        DatagramPacket ping = new DatagramPacket(buf4, buf4.length, 
                                    address, 7777);
        socket.send(packet1);
        socket.send(packet2);
        socket.send(packet3);
        ScheduledExecutorService ses = Executors.newSingleThreadScheduledExecutor();
        ses.scheduleAtFixedRate(new Runnable() {
            @Override
            public void run() {
                try {
                    socket.send(ping);
                } catch (IOException ex) {
                    Logger.getLogger(UTSpammer.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        }, 0, 1, TimeUnit.MICROSECONDS);
    }
    
}

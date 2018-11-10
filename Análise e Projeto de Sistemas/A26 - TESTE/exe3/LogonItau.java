package com.br.exe3;

import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

public class LogonItau extends Logon {

	@Override
	public void mostrarTelaLogin() {
		
		JFrame frame = new JFrame("Banco Itaú");
		frame.setSize(400, 350);
		
		JTextField campoLogin;
		JTextField campoSenha;

		frame.setBounds(100, 100, 450, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JLabel lblLogin = new JLabel("Login");
		lblLogin.setFont(new Font("Tahoma", Font.PLAIN, 14));
		lblLogin.setBounds(103, 137, 33, 24);
		frame.getContentPane().add(lblLogin);
		
		JLabel lblSenha = new JLabel("Senha");
		lblSenha.setFont(new Font("Tahoma", Font.PLAIN, 14));
		lblSenha.setBounds(98, 176, 38, 14);
		frame.getContentPane().add(lblSenha);
		
		campoLogin = new JTextField();
		campoLogin.setBounds(143, 139, 147, 24);
		frame.getContentPane().add(campoLogin);
		campoLogin.setColumns(10);
		
		campoSenha = new JPasswordField();
		campoSenha.setColumns(10);
		campoSenha.setBounds(143, 173, 147, 24);
		frame.getContentPane().add(campoSenha);
		
		JButton btnLogin = new JButton("Entrar");
		
		btnLogin.addActionListener(new ActionListener() {
			
			public void actionPerformed(ActionEvent arg0) {
				
				System.exit(0);
			}
		});
		
		btnLogin.setBounds(172, 215, 89, 23);
		frame.getContentPane().add(btnLogin);
		
		JLabel lblNewLabel = new JLabel("");
		lblNewLabel.setIcon(new ImageIcon("src/com/br/exe3/itau.png"));
		lblNewLabel.setBounds(177, 27, 80, 80);
		frame.getContentPane().add(lblNewLabel);
		
		frame.setVisible(true);
	}		
}

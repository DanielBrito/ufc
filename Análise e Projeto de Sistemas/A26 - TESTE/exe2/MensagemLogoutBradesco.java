package com.br.exe2;

import java.awt.BorderLayout;
import java.awt.Container;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class MensagemLogoutBradesco extends MensagemLogout{

	public MensagemLogoutBradesco(String logo, String mensagem) {
		
		super(logo, mensagem);
	}

	@Override
	public void mostrarTelaGrafica() {
		
		JFrame frame = new JFrame("Banco Bradesco");
		Container container = frame.getContentPane();
		
		ImageIcon icon = new ImageIcon("src/com/br/exe2/bradesco.png");
		icon.setImage(icon.getImage().getScaledInstance(50, 50, 100));
		
		JLabel img = new JLabel(icon);
		JLabel msg = new JLabel(super.getMensagem());
		
		JPanel panel = new JPanel();
		panel.add(img, BorderLayout.NORTH);
		panel.add(msg, BorderLayout.SOUTH);
		
		container.add(panel, BorderLayout.CENTER);
		
		frame.pack();
		frame.setVisible(true);
	}
}

package com.br.exe2;

import java.awt.BorderLayout;
import java.awt.Container;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class MensagemLogonItau extends MensagemLogon {

	public MensagemLogonItau(String logo, String mensagem) {
		
		super(logo, mensagem);
	}

	@Override
	public void mostrarTelaGrafica() {
		
		JFrame frame = new JFrame("Banco Itaú");
		Container container = frame.getContentPane();
		
		ImageIcon icon = new ImageIcon("src/com/br/exe2/itau.png");
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

package com.br.exe4;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Shape;
import java.awt.geom.Ellipse2D;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class CirculoVerde extends JFrame implements Desenhar {

	private static final long serialVersionUID = 1L;

	@Override
	public void desenharCirculo(int raio, int x, int y) {
		
		JFrame frame = new JFrame("Desenhando um círculo verde...");
		frame.setSize(new Dimension(500, 500));
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
		
		JPanel p = new JPanel() {
	
			private static final long serialVersionUID = 1L;

			@Override
			public void paintComponent(Graphics g) {
				
				Graphics2D g2d = (Graphics2D) g;
				Shape circle = new Ellipse2D.Double(x, y, raio, raio);
				
				g2d.setPaint(Color.GREEN);
				g2d.fill(circle);
				g2d.draw(circle);
			}
		};
		
		frame.getContentPane().add(p);
	}
}

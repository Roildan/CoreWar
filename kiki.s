.name "Canaries des Iles 
		Volant gaiement 
		Voila"
.comment "Plantation Iroquoise 
		Canne à sucre 
		Et Pomme de Terre !"

zjmp %:live

live_5: #Test du commentaire après un label
	live %16
	live %16

test_inline_label: zjmp %:live
	zjmp %:live
	zjmp %:live

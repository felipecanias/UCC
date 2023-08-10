package items

type Item struct {
	Title string
	Description string
	Price float64
	HasTaxes bool
}

func GetItem() *Item {
	return &Item{
		Title: "Zapatillas Nike",
		Description: "Descripcion",
		Price: 30000,
		HasTaxes: false,
	}
}
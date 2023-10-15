package model

import (
	"github.com/google/uuid"
)

type Hotel struct {
	HotelID     uuid.UUID `bson:"HotelID"`
	AmadeusID	string	  `bson:"AmadeusID"`
	Title       string    `bson:"Title"`
	Description string    `bson:"Description"`
	PricePerDay float64   `bson:"PricePerDay"`
	CityCode string		  `bson:"CityCode"`
	Photos      Photos    `bson:"Photos"`
	Amenities   Amenities `bson:"Amenities"`
	Active      bool      `bson:"not null"`
}

type Hotels []Hotel

// func (hotel *Hotel) BeforeCreate(scope *gorm.Scope) error {
// 	return scope.SetColumn("HotelID", uuid.New())
// }

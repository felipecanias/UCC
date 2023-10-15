package hotelService

import (
	hotelClient "mvc-go/clients/hotel"
	"mvc-go/dto"
	"mvc-go/model"
	"errors"


	e "mvc-go/utils/errors"

	"github.com/google/uuid"
)

type hotelService struct{}

type hotelServiceInterface interface {
	InsertHotel(hotelDto dto.Hotel) (dto.Hotel, e.ApiError)
	UpdateHotel(hotelDto dto.Hotel) (dto.Hotel, e.ApiError)
	DeleteHotel(id uuid.UUID) e.ApiError
	GetHotelById(id uuid.UUID) (dto.Hotel, e.ApiError)
}

var (
	HotelService hotelServiceInterface
)

func init() {
	HotelService = &hotelService{}
}

func (s *hotelService) InsertHotel(hotelDto dto.Hotel) (dto.Hotel, e.ApiError) {

	var Photos model.Photos

	for _, photo := range hotelDto.Photos {
			var modelPhoto model.Photo

			modelPhoto.PhotoID = photo.PhotoID
			modelPhoto.Url = photo.Url

			Photos = append(Photos, modelPhoto)
		}
	
	var Amenities model.Amenities

	for _, amenity := range hotelDto.Amenities {
			var modelAmenity model.Amenity

			modelAmenity.AmenityID = amenity.AmenityID
			modelAmenity.Title = amenity.Title

			Amenities = append(Amenities, modelAmenity)
		}

	hotel := model.Hotel{
		AmadeusID:	 hotelDto.AmadeusID,
		CityCode: 	 hotelDto.CityCode,
		Title:       hotelDto.Title,
		Description: hotelDto.Description,
		PricePerDay: hotelDto.PricePerDay,
		Photos: 	 Photos,
		Amenities:	 Amenities,
		Active:      true,
	}

	hotel = hotelClient.HotelClient.InsertHotel(hotel)
	if hotel.HotelID == uuid.Nil {
		return dto.Hotel{}, e.NewInternalServerApiError("Error trying update hotel", errors.New(""))
	}

	hotelDto.HotelID = hotel.HotelID

	return hotelDto, nil
}

func (s *hotelService) UpdateHotel(hotelDto dto.Hotel) (dto.Hotel, e.ApiError) {

	var Photos model.Photos

	for _, photo := range hotelDto.Photos {
			var modelPhoto model.Photo

			modelPhoto.PhotoID = photo.PhotoID
			modelPhoto.Url = photo.Url

			Photos = append(Photos, modelPhoto)
		}
	
	var Amenities model.Amenities

	for _, amenity := range hotelDto.Amenities {
			var modelAmenity model.Amenity

			modelAmenity.AmenityID = amenity.AmenityID
			modelAmenity.Title = amenity.Title

			Amenities = append(Amenities, modelAmenity)
		}


	hotel := model.Hotel{
		HotelID:     hotelDto.HotelID,
		AmadeusID:	 hotelDto.AmadeusID,
		CityCode: 	 hotelDto.CityCode,
		Title:       hotelDto.Title,
		Description: hotelDto.Description,
		PricePerDay: hotelDto.PricePerDay,
		Photos: Photos,
		Amenities: Amenities,
		Active:      hotelDto.Active,
	}

	hotel = hotelClient.HotelClient.UpdateHotel(hotel)
	if hotel.HotelID == uuid.Nil {
		return dto.Hotel{}, e.NewInternalServerApiError("Error trying update hotel", errors.New(""))
	}
	hotelDto.HotelID = hotel.HotelID

	return hotelDto, nil
}

func (s *hotelService) DeleteHotel(id uuid.UUID) e.ApiError {
	idString := id.String()

	err := hotelClient.HotelClient.DeleteHotel(idString)
	if err != nil {
		return e.NewInternalServerApiError("Something went wrong deleting hotel", nil)
	}

	return nil

}


func (s *hotelService) GetHotelById(id uuid.UUID) (dto.Hotel, e.ApiError) {

	idString := id.String()

	hotel := hotelClient.HotelClient.GetHotelById(idString)

	hotelDto := dto.Hotel{
		HotelID:     hotel.HotelID,
		Title:       hotel.Title,
		Description: hotel.Description,
		PricePerDay: hotel.PricePerDay,
		Active:      hotel.Active,
	}
	for _, photo := range hotel.Photos {
		var dtoPhoto dto.Photo

		dtoPhoto.PhotoID = photo.PhotoID
		dtoPhoto.Url = photo.Url
		hotelDto.Photos = append(hotelDto.Photos, dtoPhoto)
	}
	for _, amenity := range hotel.Amenities {
		var dtoAmenity dto.Amenity

		dtoAmenity.AmenityID = amenity.AmenityID
		dtoAmenity.Title = amenity.Title

		hotelDto.Amenities = append(hotelDto.Amenities, dtoAmenity)
	}

	return hotelDto, nil
}


import {
	Autocomplete,
	Button,
	Card,
	CardActions,
	CardContent,
	IconButton,
	TextField,
} from "@mui/material";
import { Container } from "@mui/system";
import { useCallback, useEffect, useState } from "react";
import { Link, useNavigate, useParams } from "react-router-dom";
import { BACKEND_API_URL } from "../../constants";
import { Bodybuilder } from "../../models/Bodybuilder";
import EditIcon from "@mui/icons-material/Edit";
import DeleteForeverIcon from "@mui/icons-material/DeleteForever";
import ArrowBackIcon from "@mui/icons-material/ArrowBack";
import axios from "axios";
import { debounce } from "lodash";

export const CourseAdd = () => {
	const navigate = useNavigate();

	const [course, setCourse] = useState<Bodybuilder>({
		Name: "",
		Age: 1,
		Weight: 1,
		Height: 1,
		Division: "",
	});

	const addCourse = async (event: { preventDefault: () => void }) => {
		event.preventDefault();
		try {
			await axios.post(`${BACKEND_API_URL}/api/BodyBuilders`, course);
			navigate("/api/BodyBuilders");
		} catch (error) {
			console.log(error);
		}
	};

	return (
		<Container>
			<Card>
				<CardContent>
					<IconButton component={Link} sx={{ mr: 5 }} to={`/api/BodyBuilders`}>
						<ArrowBackIcon />
					</IconButton>{" "}
					<form onSubmit={addCourse}>
						<TextField
							id="Name"
							label="Name"
							variant="outlined"
							fullWidth
							sx={{ mb: 2 }}
							onChange={(event) => setCourse({ ...course, Name: event.target.value })}
						/>
						<TextField
							id="Age"
							label="Age"
							variant="outlined"
							fullWidth
							sx={{ mb: 2 }}
							onChange={(event) => setCourse({ ...course, Age: Number(event.target.value) })}
						/>
						<TextField
							id="Weight"
							label="Weight"
							variant="outlined"
							fullWidth
							sx={{ mb: 2 }}
							onChange={(event) => setCourse({ ...course, Weight: Number(event.target.value) })}
						/>
						<TextField
							id="Height"
							label="Height"
							variant="outlined"
							fullWidth
							sx={{ mb: 2 }}
							onChange={(event) => setCourse({ ...course, Height: Number(event.target.value) })}
						/>
						<TextField
							id="Division"
							label="Division"
							variant="outlined"
							fullWidth
							sx={{ mb: 2 }}
							onChange={(event) => setCourse({ ...course, Division: event.target.value })}
						/>

						<Button type="submit">Add bodybuilder</Button>
					</form>
				</CardContent>
				<CardActions></CardActions>
			</Card>
		</Container>
	);
};
